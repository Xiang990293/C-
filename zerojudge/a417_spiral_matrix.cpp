#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int total, size;
	
	int clockwise;
	
	cin >> total;
	for(int i=0; i<total; i++){
		cin >> size >> clockwise;
		
		for(int x=0; x<size; x++){
			int left = ceil(-1 * abs(x-(size-1)/2)+(size-1)/2);
			int middle = abs(-2*x + size);
			int right = left;
			
			for(int l=0; l<left; l++){
				cout << "\t1";
			}
			
			for(int m=left-1; m<middle; m++){
				cout << "\t2";
			}
			
			for(int r=left+middle; r<2*left+middle; r++){
				cout << "\t3";
			}
			
			cout << endl;
		}
	}
	
	return 0;
} 
