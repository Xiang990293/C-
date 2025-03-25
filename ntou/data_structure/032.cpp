#include<iostream>
#include"Node.cpp"
using namespace std;

int main(){
	Node Data(0);

	Data.next = new Node(0);
	Node *current_Node = Data.next;
	int array_data[8] = {88,77,66,55,44,33,22,11};

	for(int i=0; i<8; i++){
		current_Node->data = array_data[i];
		current_Node->next = new Node();
		current_Node = current_Node->next;
	}

	Data.print_list("原來串列");

	Data.insert(90, 0);
	
	Data.print_list("插入後串列");

	Data.delete_Node(55);

	Data.print_list("插入後串列");

	int find;
	int value;
	cout << "請輸入插入其後的郵件編號 ==> " ;
	cin >> find;
	cout << "請輸入新的郵件編號 ==> " ;
	cin >> value;
	while (find != -1) {
		Data.insert(value, find);
		Data.print_list("插入後串列");
		cout << "請輸入插入其後的郵件編號 ==> " ;
		cin >> find;
		cout << "請輸入新的郵件編號 ==> " ;
		cin >> value;
	}
	
}