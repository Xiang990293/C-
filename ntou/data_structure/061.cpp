#include<iostream>
#include"060.cpp"
using namespace std;

struct struct_array_binary_tree {
	int value;
	int left_index;
	int right_index;
};

// int main(){
// 	int data[15] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
// 	struct_array_binary_tree tree[10];

// 	for(int i=0; i<10; i++){
// 		tree[i].value = 0;
// 		tree[i].left_index = tree[i].right_index = -1;
// 	}

// 	tree[0].value = data[0];

// 	for(int i = 0; i< 10; i++){
// 		tree[i].value = data[i];
// 	}
// }