#include<iostream>
using namespace std;

int main(){
	int array[8]={0,1,2,3,4,5,6,7};

	for(int i=0; i<8; i++){
		cout << array[i] << " ";
	}
	cout << endl;

	for(int i=0; i<8; i++){
		cout << *(array+i) << " ";
	}
	cout << endl;

	int *ptr = array;
	for(int i=0; i<8; i++){
		cout << *ptr++ << " ";
	}
	cout << endl;
}