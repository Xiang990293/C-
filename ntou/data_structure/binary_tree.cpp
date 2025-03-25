#include<iostream>
#include"binary_tree_node.cpp"
#include"stack.cpp"
#include<sstream>
using namespace std;

template <typename T>
struct binary_tree{
	binary_tree_node<T>* start;
	int length = 0;

	binary_tree() {
		start = new binary_tree_node<T>(0);
	}

	bool is_empty(){
		return length==0;
	}

	void put(int input) {
		binary_tree_node<T>* temp = start;
		if(length == 0) {
			start->value = input;
			length++;
			return;
		}
		while(true){
			if(input > temp->value) 
				if(temp->right == nullptr) {
					temp->right = new binary_tree_node<T>(input);
					length++;
					return;
				}
				else temp = temp->right;
			if(input < temp->value) 
				if(temp->left == nullptr) {
					temp->left = new binary_tree_node<T>(input);
					length++;
					return;
				}
				else temp = temp->left;
		}
	}

	void print(){
		binary_tree_node<T>* ptr = start;
		
		cout << "根節點：[" << ptr->value << "]" << endl;
		cout << "左子樹：";
		ptr = ptr->left;
		while(ptr != nullptr){
			cout << "[" << ptr->value << "]";
			ptr = ptr->left;
		}
		cout << endl;
		ptr = start;
		cout << "右子樹：";
		ptr = ptr->right;
		while(ptr != nullptr){
			cout << "[" << ptr->value << "]";
			ptr = ptr->right;
		}
		cout << endl;
	}

	string print_L2R(){
		binary_tree_node<T>* ptr = start;
		stack have_child = stack<T>();
		if(ptr->left != nullptr){
			have_child.push(ptr)
		}
		
		cout << "根節點：[" << ptr->value << "]" << endl;
		cout << "左子樹：";
		ptr = ptr->left;
		while(ptr != nullptr){
			cout << "[" << ptr->value << "]";
			ptr = ptr->left;
		}
		cout << endl;
		ptr = start;
		cout << "右子樹：";
		ptr = ptr->right;
		while(ptr != nullptr){
			cout << "[" << ptr->value << "]";
			ptr = ptr->right;
		}
		cout << endl;
	}
};