#include<iostream>
using namespace std;

template <typename T>
struct binary_tree_node{
	T value;
	binary_tree_node* left;
	binary_tree_node* right;

	binary_tree_node(T value1){
		value = value1;
		left = nullptr;
		right = nullptr;
	}

	binary_tree_node(){
		value = T();
		left = nullptr;
		right = nullptr;
	}
};