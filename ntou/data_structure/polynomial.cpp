#include<iostream>
using namespace std;

struct node{
	float coef;
	int exp;
	node *next;

	node(){
		coef = 0;
		exp = 0;
		next = NULL;
	}

	node(int node_coef){
		coef = node_coef;
		exp = 0;
		next = NULL;
	}

	node(int node_coef, int node_exp){
		coef = node_coef;
		exp = node_exp;
		next = NULL;
	}

	node(int node_coef, int node_exp, node *next_node_ptr){
		coef = node_coef;
		exp = node_exp;
		next = next_node_ptr;
	}

	void print(){
		cout << coef<<"x^"<<exp;
	}

	void print_list(){
		node *current_node = this->next;
		while(current_node->next->next != this){
			current_node->print();
			cout << "+";
			current_node = current_node->next;
		}
		current_node->print() ;
		// cout << current_node->next->print();
		cout << endl;
	}

	// bool have(int find){
	// 	node *current_node = this;
	// 	while (true) {
	// 		if (current_node->data == find) {
	// 			return true;
	// 		}

	// 		if (current_node->next == NULL) {
	// 			return false;
	// 		}
	// 		current_node = current_node->next;
	// 	}
	// }

	// void delete_node(int find){
	// 	node *current_node = this;
	// 	node *previous_node;
	// 	while (true) {
	// 		if (current_node->data == find) {
	// 			if (current_node == this) {
	// 				*this = *(current_node->next);
	// 			} else {
	// 				previous_node->next = previous_node->next->next;
	// 			}
	// 			break;
	// 		}

	// 		if (!this->have(find)) break;
	// 		previous_node = current_node;
	// 		current_node = current_node->next;
	// 	}
	// }

	// void insert(int insert_num, int pos_to_insert){
	// 	node *current = this;
	// 	node *previous = nullptr;

	// 	while (current != nullptr && current->data != pos_to_insert) {
	// 		previous = current;
	// 		current = current->next;
	// 	}

	// 	if (current == nullptr) {
	// 		cout << "Position " << pos_to_insert << " not found in the list." << endl;
	// 		return;
	// 	}

	// 	node *add = new node(insert_num);
	// 	add->next = current->next;

	// 	if (current != nullptr)
	// 		current->next = add;
	// 	else
	// 		this->next = add;
	// }
};