#include"node.cpp"
#include<iostream>
#include<sstream>
using namespace std;

template <typename T>
struct chain_list{
	node<T>* start = new node<T>();
	node<T>* end = start;
	int length = 0;

	void push(node<T>* nexti){
		end->next = nexti;
		end = nexti;
		length++;
	}

	int delete_node(int index){
		if(index < 0) return -1;
		if(index >= length) return -1;
		node<T>* temp = start;
		for(int i=0; i < index; i++){
			temp = temp->next;
		}
		int result = temp->next->value;
		temp->next = temp->next->next;
		length--;

		return result;
	}

	void add_node(int index, node<T>* nodei){
		node<T>* temp = start;
		for(int i=0; i < index; i++){
			if(temp->next == nullptr) return;
			temp = temp->next;
		}
		nodei->next = temp->next;
		temp->next = nodei;
		length++;
	}

	int pop(){
		delete_node(length--);
	}

	string print(){
		string output = "";
		stringstream s;
		
		for(node<T>* temp = start; temp != end; temp = temp->next){
			s << "[" << (temp->next->value) << "]";
		}
		getline(s, output);

		return output;
	}
};