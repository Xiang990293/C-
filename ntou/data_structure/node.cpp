#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;

	Node(){
		data = 0;
		next = NULL;
	}

	Node(int node_data){
		data = node_data;
		next = NULL;
	}

	Node(int node_data, Node *next_node_ptr){
		data = node_data;
		next = next_node_ptr;
	}

	string print(){
		return "["+to_string(data)+"]";
	}

	void print_list(string head){
		Node copy = *this->next;
		Node *current_node = &copy;
		cout << head <<"：" ;
		while(current_node->next != NULL && current_node->next != this){
			cout << current_node->print();
			current_node = current_node->next;
		}
		cout << endl;
	}

	bool have(int find){
		Node *current_node = this;
		while (true) {
			if (current_node->data == find) {
				return true;
			}

			if (current_node->next == NULL) {
				return false;
			}
			current_node = current_node->next;
		}
	}

	void delete_node(int find){
		Node *current_node = this;
		Node *previous_node;
		while (true) {
			if (current_node->data == find) {
				if (current_node == this) {
					*this = *(current_node->next);
				} else {
					previous_node->next = previous_node->next->next;
				}
				break;
			}

			if (!this->have(find)) break;
			previous_node = current_node;
			current_node = current_node->next;
		}
	}

	void insert(int insert_num, int pos_to_insert){
		Node *current = this;
		Node *previous = nullptr;

		while (current != nullptr && current->data != pos_to_insert) {
			previous = current;
			current = current->next;
		}

		if (current == nullptr) {
			cout << "Position " << pos_to_insert << " not found in the list." << endl;
			return;
		}

		Node *add = new Node(insert_num);
		add->next = current->next;

		if (current != nullptr)
			current->next = add;
		else
			this->next = add;
	}
};