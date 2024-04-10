#include<stdio.h>
#include<stdlib.h>

typedef struct Node SNode;
typedef SNode *LStack;
LStack top = NULL;

struct Node{
	int data;
	struct Node *next;
};

extern int isStackEmpty();
extern void push(int d);
extern int pop();