#include"node.cpp"
#include<iostream>
using namespace std;

struct chain_list{
	node* start = new node(-1, -1);
	node* end = start;
	int length = 0;

	void push(node* nexti){
		end->next = nexti;
		end = nexti;
		length++;
	}

	void delete_node(int index){
		if(index < 0) return;
		if(index >= length) return;
		node* temp = start;
		for(int i=0; i < index; i++){
			temp = temp->next;
		}
		temp->next = temp->next->next;
		length--;
	}

	void add_node(int index, node* nodei){
		node* temp = start;
		for(int i=0; i < index; i++){
			if(temp->next == nullptr) return;
			temp = temp->next;
		}
		nodei->next = temp->next;
		temp->next = nodei;
		length++;
	}

	void pop(){
		delete_node(length-1);
		length--;
	}

	string print(){
		string output = "";
		
		for(node* temp = start; temp != end; temp = temp->next){
			if(temp->next->count >= 2){
				output+= temp->next->prime+"^"+temp->next->count;
				if(temp->next != end)
					output += " * ";
			}else if(temp->next->count == 1){
				output+= temp->next->prime;
				if(temp->next != end)
					output += " * ";
			}
		}

		return output;
	}
};