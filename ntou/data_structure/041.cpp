#include"stack_node.cpp"

void push(int d) {
	LStack new_node;
	new_node = (LStack)malloc(sizeof(SNode));
	new_node->data = d;
	new_node->next = top;
	top = new_node;
	return;
}

int pop(){
	LStack ptr;
	int temp;
	if (!isStackEmpty()) {
		ptr = top;
		top = top->next;
		temp = ptr->data;
		free(ptr);
		return temp;
	}
	return -1;
}

int main(){
	int data[8] = {20,21,22,23,24,25,26,27};
	Node a;

	printf("存入堆疊的順序：\n");
	for(int i=0; i<8; i++){
		push(data[i]);
		printf("[%d]",data[i]);
	}
	
	printf("\n取出堆疊的順序：\n");
	for(int i=0; i<8; i++){
		printf("[%d]",pop());
	}
}