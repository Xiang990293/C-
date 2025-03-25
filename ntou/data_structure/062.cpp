#include<iostream>
#include"binary_tree.cpp"
using namespace std;

int main(){
	binary_tree tree = binary_tree();
	int data[16] = {1, 7, 4, 6, 19, 8,3, 11, 21, 27, 24, 26, 219, 28, 23, 211};

	for(int i=0; i<10; i++){
		tree.put(data[i]);
	}

	tree.print();
}