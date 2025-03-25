#include<iostream>
#include<cstdlib>
#include<cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// #define BYTE unsigned char
// #define WORD unsigned short
// #define DWORD unsigned int

// #pragma pack(push)
// #pragma pack(2)
// struct BITMAPFILEHEADER{
// 	WORD bfType;
// 	DWORD bfSize;
// 	WORD bfReserved1;
// 	WORD bfReserved2;
// 	DWORD bfOffBits;
// };
// #pragma pack(pop)

// struct BITMAPINFOHEADER{
// 	DWORD biSize;
// 	int biWidth;
// 	int biHeight;
// 	WORD biPlanes;
// 	WORD biBitCount;
// 	DWORD biCompression;
// 	DWORD biSizeImage;
// 	int biXPelsPerMeter;
// 	int biYPelsPerMeter;
// 	DWORD biClrUsed;
// 	DWORD biClrImportant;
// };

// class ImageMatrix{
// public:
// 	int height;
// 	int width;
// 	int rowsize;
// 	BYTE* term;

// 	ImageMatrix(){
// 		height = 0;
// 		width=0;
// 	}

// 	ImageMatrix(int height, int width){
// 		this->height=height;
// 		this->width=width;
// 		rowsize = (3*width+3)/4*4;
// 		term = new BYTE[height*rowsize];
// 	}

// 	bool Load(char* filename){
// 		BITMAPFILEHEADER h;
// 		BITMAPINFOHEADER hInfo;
// 		ifstream f;
// 		f.open(filename, ios::binary);
// 		f.read((char*)&h, sizeof(h));
// 		f.read((char*)&hInfo, sizeof(hInfo));
// 		if(h.bfType != 0x4d42
// 		|| hInfo.biClrUsed != 0
// 		|| hInfo.biBitCount != 24
// 		|| hInfo.biCompression != 0
// 		|| hInfo.biPlanes != 1){
// 			f.close();
// 			return 0;
// 		}

// 		width = hInfo.biWidth;
// 		height = hInfo.biHeight;
// 		*this = ImageMatrix(height, width);
// 		f.read((char*)term, height*rowsize);
// 		f.close();
// 		return 1;
// 	}

// 	bool Save(char* filename){
// 		BITMAPFILEHEADER h = {
// 			0x4d42,
// 			54+ rowsize*height,
// 			0,
// 			0,
// 			54
// 		};
// 		BITMAPINFOHEADER hInfo = {
// 			40,
// 			width,
// 			height,
// 			1,
// 			21,
// 			0,
// 			rowsize*height,
// 			3780,
// 			3780,
// 			0,
// 			0
// 		};
// 		ofstream f;
// 		f.open(filename, ios::binary);
// 		f.write((char*)&h, sizeof(h));
// 		f.write((char*)&hInfo, sizeof(hInfo));
// 		f.write((char*)term, rowsize*height);
// 		f.close();
// 		return 1;
// 	}
// };

long double input_to_hidden_sigmoid_function(long double input){
	return (2/((1+exp(-2*(input))))-1);
}

long double hidden_to_output_unnormalize_function(long double hidden, long double min, long double max){
	return (hidden+1)/2*(max-min)+min;
}

int main(){
	int tempi;
	string temps;
	long double tempf;
	ifstream Config_Input("ANNSFM_Config_I.txt"); // 輸入值的各個節點資料範圍(用於正規化輸入資料，及反推推測資料用)
	ifstream Config_Output("ANNSFM_Config_O.txt"); // 輸入值的各個節點資料範圍(用於正規化輸入資料，及反推推測資料用)
	ifstream Config_Node_Count("ANNSFM_Config_S.txt"); // 各層的節點個數
	ifstream B_Hidden("ANNSFM_CS_HB.txt"); // 隱藏層的線性偏移值
	ifstream W_Input_to_Hidden("ANNSFM_CS_HW.txt"); // 輸入層的權重
	ifstream B_Outout("ANNSFM_CS_OB.txt"); // 輸出層的線性偏移值
	ifstream W_Hidden_to_Output("ANNSFM_CS_OW.txt"); // 隱藏層的權重
	ifstream data_size("ANNSFM_data_size.txt"); // 資料筆數，用於for迴圈使用者
	ifstream Input("ANNSFM_inputs.txt"); // 輸入之資料

	// 讀入節點數 (每行一個數字)
	vector<int> node_count; // 每層節點數
	int layer; // 層數
	for(layer=0; getline(Config_Node_Count, temps); layer++) { 
		node_count.push_back(stoi(temps));
	}
	
	// 讀入輸入值範圍 (先最小，再最大)
	long double Input_range[node_count[0]][2]; // 輸入值範圍[節點編號][最小=0/最大=1]
	for(int i=0; getline(Config_Input, temps); i++) {
		stringstream sline;
		sline << temps;
		
		for(int j=0; j<node_count[0]; j++) {
			sline >> Input_range[j][i];
			if(sline.fail()) break;
		}
	}
	
	// 讀入輸出值範圍 (先最小，再最大)
	long double Output_range[node_count[layer-1]][2]; // 輸入值範圍[節點編號][最小=0/最大=1]
	for(int i=0; getline(Config_Output, temps); i++) {
		stringstream sline;
		sline << temps;
		
		for(int j=0; j<node_count[layer-1]; j++) {
			sline >> Output_range[j][i];
			if(sline.fail()) break;
		}
	}

	// 取得輸入到隱藏層的權重
	long double weight_ith[node_count[1]][node_count[0]];
	for(int i=0; i<node_count[1]; i++){
		getline(W_Input_to_Hidden, temps);
		stringstream sline;
		sline << temps;

		for(int j=0; j<node_count[0]; j++){
			sline >> weight_ith[i][j];
			if(sline.fail()) break;
		}
	}

	// 取得隱藏層的偏移
	long double bias_h[node_count[1]];
	for(int i=0; i<node_count[1]; i++){
		getline(B_Hidden, temps);
		bias_h[i] = stold(temps);
	}

	// 取得隱藏層到輸出的權重
	long double weight_hto[node_count[2]][node_count[1]];
	for(int i=0; i<node_count[2]; i++){
		getline(W_Hidden_to_Output, temps);
		stringstream sline;
		sline << temps;

		for(int j=0; j<node_count[1]; j++){
			sline >> weight_hto[i][j];
			if(sline.fail()) break;
		}
	}

	// 取得輸出層的偏移
	long double bias_o[node_count[2]];
	for(int i=0; i<node_count[2]; i++){
		getline(B_Outout, temps);
		bias_o[i] = stold(temps);
	}

	// 取得資料數目
	getline(data_size, temps);
	int dsize = stoi(temps); // 載入資料數目

	// 取得資料，同時將其正規化
	long double data[node_count[0]][dsize];
	for(int i=0; getline(Input, temps); i++) {
		stringstream sline;
		sline << temps;
		
		for(int j=0; j<node_count[0]; j++) {
			sline >> data[j][i];
			data[j][i] = (2*(data[j][i]-Input_range[j][0])/(Input_range[j][1]-Input_range[j][0])-1);
			if(sline.fail()) break;
		}
	}


	ofstream Output("ANNSFM_outputs.txt"); // 輸出之資料
	if(Output.is_open()){
		for(int line=0; line<dsize; line++){ // 對每行輸入進行運算
			long double hidden[node_count[1]] = {};
			for(int nodes=0; nodes<node_count[1]; nodes++){
				for(int nodes_prev_layer=0; nodes_prev_layer<node_count[0]; nodes_prev_layer++){
					hidden[nodes] += data[nodes_prev_layer][line] * weight_ith[nodes][nodes_prev_layer];
					// cout << data[nodes_prev_layer][line] << "*" << weight_ith[nodes][nodes_prev_layer] << "=" << hidden[nodes] << endl;
					// if((hidden[nodes].isnan()) == true) cin >> tempi;
				}
				hidden[nodes] += bias_h[nodes];
				hidden[nodes] = input_to_hidden_sigmoid_function(hidden[nodes]);
			}

			long double sum = 0;
			for(int nodes=0; nodes<node_count[2]; nodes++){
				for(int nodes_prev_layer=0; nodes_prev_layer<node_count[1]; nodes_prev_layer++){
					sum += hidden[nodes_prev_layer] * weight_hto[nodes][nodes_prev_layer];
				}
				sum += bias_o[nodes];
				// cout << Output_range[nodes][0] << " " << Output_range[nodes][1] << endl;
				Output << hidden_to_output_unnormalize_function(sum, Output_range[nodes][0], Output_range[nodes][1]) << endl;
			}
		}
		
		
	}
	
	return 0;
} 