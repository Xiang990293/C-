#include<iostream>
#include"stack.cpp"
#include"binary_tree.cpp"
using namespace std;

int main(){
	stack a = stack<binary_tree_node<int>>();

	a.push(binary_tree_node<int>(1));
	a.print();
}