#include<iostream>
using namespace std;

int main(){
	int *value[9];
	int array[9]={20,21,22,23,24,25,26,27,28};

	for(int i=0; i<9; i++){
		value[i] = &(array[i]);
	}

	for(int i=0; i<9; i++){
		cout << **(value+i) << " ";
	}
	cout << endl;
}