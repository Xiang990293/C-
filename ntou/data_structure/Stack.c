/* �{���d��: Stack.c */
#include "stack_node.h"
/* ���: �ˬd���|�O�_�O�Ū� */
int isStackEmpty() {
   if ( top == NULL ) return 1;
   else               return 0;
}
/* ���: �N��Ʀs�J���| */
void push(int d) {
   LStack new_node;            /* �s�`�I���� */
   /* �t�m�`�I�O���� */
   new_node = (LStack)malloc(sizeof(SNode));
   new_node->data = d;         /* �إ߸`�I���e */
   new_node->next = top;       /* �s�`�I���V��}�l */
   top = new_node;             /* �s�`�I�������|�}�l */   
}
/* ���: �q���|���X��� */
int pop() {
   LStack ptr;                 /* ���V���|���� */
   int temp;
   if ( !isStackEmpty()  ) {   /* ���|�O�_�O�Ū� */
      ptr = top;               /* ���V���|���� */
      top = top->next;         /* ���|���Ы��V�U�`�I */
      temp = ptr->data;        /* ���X��� */
      free(ptr);               /* ���^�`�I�O���� */
      return temp;             /* ���|���X */
   }
   else return -1;
}
