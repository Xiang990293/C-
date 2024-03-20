#include<iostream>
using namespace std;

int main(){
	string data[4][5] = {
		{"學號	", "姓名", "數學", "英文", "電腦"},
		{"01181020", "陳天裕", "20", "22", "24"},
		{"01181010", "陳佑寧", "10", "12", "14"},
		{"01181001", "陳廣棟", "1", "3", "5"}
	};

	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			cout << data[i][j] << "\t";
		}
		cout << endl;
	}
}