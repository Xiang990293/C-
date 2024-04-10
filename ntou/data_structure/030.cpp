#include<iostream>
#include"node.cpp"
using namespace std;

int main(){
	node Data(88);

	node *current_node = &Data;
	int array_data[8] = {88,77,66,55,44,33,22,11};

	cout << "原來串列：" ;
	for(int i=0; i<8; i++){
		current_node->data = array_data[i];
		current_node->next = new node();
		cout << current_node->print();
		current_node = current_node->next;
	}
	cout << endl;

	cout << "串列是否為空：" << (&Data == NULL) << endl;
	
	cout << "請輸入搜尋的郵件編號 ==> " ;
	int find;
	cin >> find;
	while (find != -1) {

		current_node = &Data;
		while (true) {
			if (current_node->data == find) {
				cout << "串列包含節點["+to_string(find)+"]" << endl;
				break;
			}

			if (current_node->next == NULL) {
				cout << "串列不包含節點["+to_string(find)+"]" << endl;
				break;
			}
			current_node = current_node->next;
		}
		cout << "請輸入搜尋的郵件編號 ==> " ;
		cin >> find;
	}
	
}