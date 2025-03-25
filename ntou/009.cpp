#include<iostream>
using namespace std;

struct vect{
	int size = 1;
	vect(int size){
		int val[size] = {};
	}
};

int main(){
	int row, col;
	int temp;
	
	cout << "請輸入行數和列數後，每行輸入列數個數字，如：" << endl
	<< "3 3" << endl
	<< "1 2 3" << endl
	<< "4 75 6" << endl
	<< "7 8 93" << endl;
	while(cin >> row >> col){
		int mat1[row][col];
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cin >> mat1[i][j];
			}
		}

		int mat2[row][col];
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cin >> mat2[i][j];
			}
		}

		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				int sum = 0;
				for(int k=0; k<row; k++){
					sum += mat1[i][k] * mat2[k][j];
				}
				cout << sum << " ";
			}
			cout << endl;
		}
	}
}