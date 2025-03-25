#include<iostream>
using namespace std;

#define MAXSTACK 100

struct stack_array{
	int top = -1;
	int stack[MAXSTACK];

	bool isStackEmpty() {
		if (top == -1) return true;
		else return false;
	}

	int push(int d) {
		if (top >= MAXSTACK) {
			printf("堆疊內容全滿\n");
			return 0;
		}
		else {
			stack[++top] = d;
			return 1;
		}
	}

	int pop(){
		if (isStackEmpty())return -1;
		else return stack[top--];
	}
};

int main() {
	int data[8] = {20,21,22,23,24,25,26,27};
	stack_array a;

	printf("存入堆疊的順序：\n");
	for(int i=0; i<8; i++){
		a.push(data[i]);
		printf("[%d]",data[i]);
	}
	
	printf("\n取出堆疊的順序：\n");
	for(int i=0; i<8; i++){
		printf("[%d]",a.pop());
	}
}