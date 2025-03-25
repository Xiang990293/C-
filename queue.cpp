#include"chain_list.cpp"
using namespace std;

template <typename T>
struct queue{
	chain_list<T> values;

	void push(int input){
		values.push(new node<T>(input));
	}

	int pop(){
		return values.delete_node(0);
	}
};