#include"chain_list.cpp"
using namespace std;

struct input_limited_queue{
	chain_list values;

	void push(int input){
		values.push(new node(input));
	}

	int pop(int mode){
		return values.delete_node((2-mode)*(values.length-1));
	}
};

struct output_limited_queue{
	chain_list values;

	void push(int input, int mode){
		values.add_node((2-mode)*(values.length),new node(input));
	}

	int pop(){
		return values.delete_node(0);
	}
};