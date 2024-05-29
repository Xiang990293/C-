#include<iostream>
using namespace std;

#define MAXQUEUE 100

struct queue{
	int values[MAXQUEUE];
	int start = 0;
	int length = 0;

	void push(int input){
		if (length == MAXQUEUE) return;
		values[length++] = input;
	}

	int pop(){
		if (start == length) return -1;
		length--;
		return values[start++];
	}

	void print(){
		for(int i=0; i<length; i++){
			cout << "[" << values[start+i] << "]";
		}
		cout << endl;
	}
};


int main(){
	queue a;

	for(int i=20; i<32; i++){
		a.push(i);
		a.print();
	}

	for(int i=20; i<32; i++){
		cout << a.pop() << endl;
		a.print();
	}
}