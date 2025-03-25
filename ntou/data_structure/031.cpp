#include<iostream>
#include"node.cpp"
using namespace std;

int main(){
	node Data(88);

	node *current_node = &Data;
	int array_data[8] = {88,77,66,55,44,33,22,11};

	for(int i=0; i<8; i++){
		current_node->data = array_data[i];
		current_node->next = new node();
		current_node = current_node->next;
	}

	Data.print_list("原來串列");
	
	cout << "請輸入刪除的郵件編號 ==> " ;
	int find;
	cin >> find;
	while (find != -1) {

		current_node = &Data;
		node *previous_node;
		while (true) {
			if (current_node->data == find) {
				cout << "刪除節點["+to_string(find)+"]" << endl;
				if (current_node == &Data) {
					Data = *(current_node->next);
				} else {
					previous_node->next = previous_node->next->next;
				}
				Data.print_list("刪除後串列");
				break;
			}

			if (current_node->next == NULL) {
				cout << "串列不包含節點["+to_string(find)+"]" << endl;
				break;
			}
			previous_node = current_node;
			current_node = current_node->next;
		}
		cout << "請輸入刪除的郵件編號 ==> " ;
		cin >> find;
	}
	
}