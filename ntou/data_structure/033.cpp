#include<iostream>
#include"polynomial.cpp"
using namespace std;

int main(){
	node A(0,-1);
	node B(0,-1);

	A.next = new node(0);
	B.next = new node(0);
	node *current_node = A.next;
	int A_array[2][2] = {{5,6},{2,0}};

	for(int i=0; i<2; i++){
		current_node->coef = A_array[i][0];
		current_node->exp = A_array[i][1];
		current_node->next = new node();
		current_node = current_node->next;
	}

	current_node->next = &A;
	A.print_list();

	current_node = B.next;
	int B_array[2][2] = {{9,3},{1,0}};

	for(int i=0; i<2; i++){
		current_node->coef = B_array[i][0];
		current_node->exp = B_array[i][1];
		current_node->next = new node();
		current_node = current_node->next;
	}

	current_node->next = &B;
	B.print_list();

	// int find;
	// int value;
	// cout << "請輸入插入其後的郵件編號 ==> " ;
	// cin >> find;
	// cout << "請輸入新的郵件編號 ==> " ;
	// cin >> value;
	// while (find != -1) {
	// 	Data.insert(value, find);
	// 	Data.print_list("插入後串列");
	// 	cout << "請輸入插入其後的郵件編號 ==> " ;
	// 	cin >> find;
	// 	cout << "請輸入新的郵件編號 ==> " ;
	// 	cin >> value;
	// }
}