#include<iostream>
using namespace std;

#define MAX_LENGTH 100

struct array_binary_tree{
	int value[MAX_LENGTH];
	int length;

	array_binary_tree(){
		value[MAX_LENGTH] = {};
		value[0] = -1;
		for(int i = 1; i< MAX_LENGTH; i++) value[i] = -1; 
	}

	void put(int input){
		put_num(input, 1);
	}
	
	void put_num(int input, int check_pos){
		if(value[check_pos] == -1) {
			value[check_pos] = input;
			length++;
			return;
		}
		if(input < value[check_pos]) put_num(input, check_pos*2);
		if(input > value[check_pos]) put_num(input, check_pos*2+1);
		return;
	}

	void print(){
		for(int i = 0, printted = 0; i<MAX_LENGTH; i++) {
			if(value[i] != -1) {
				cout << "[" << i << ":" << value[i] << "]";
				printted++;
			}

			if(printted == length) break;
		}
		cout << endl;
	}
};

int main(){
	array_binary_tree tree = array_binary_tree();
	int data[15] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	for(int i=0; i<10; i++) tree.put(data[i]);
	tree.print();
}