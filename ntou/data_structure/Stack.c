/* 嚙緹嚙踝蕭嚙範嚙踝蕭: Stack.c */
#include "stack_node.h"
/* 嚙踝蕭嚙�: 嚙誼查嚙踝蕭嚙罵嚙瞌嚙稻嚙瞌嚙褐迎蕭 */
int isStackEmpty() {
   if ( top == NULL ) return 1;
   else               return 0;
}
/* 嚙踝蕭嚙�: 嚙瞇嚙踝蕭�存嚙皚嚙踝蕭嚙罵 */
void push(int d) {
   LStack new_node;            /* 嚙編嚙窯嚙瘢嚙踝蕭嚙踝蕭 */
   /* 嚙緣嚙練嚙窯嚙瘢嚙瞌嚙踝蕭嚙踝蕭 */
   new_node = (LStack)malloc(sizeof(SNode));
   new_node->data = d;         /* 嚙諍立節嚙瘢嚙踝蕭嚙箴 */
   new_node->next = top;       /* 嚙編嚙窯嚙瘢嚙踝蕭嚙碾嚙踝蕭}嚙締 */
   top = new_node;             /* 嚙編嚙窯嚙瘢嚙踝蕭嚙踝蕭嚙踝蕭嚙罵嚙罷嚙締 */   
}
/* 嚙踝蕭嚙�: 嚙緬嚙踝蕭嚙罵嚙踝蕭嚙碼嚙踝蕭嚙� */
int pop() {
   LStack ptr;                 /* 嚙踝蕭嚙碾嚙踝蕭嚙罵嚙踝蕭嚙踝蕭 */
   int temp;
   if ( !isStackEmpty()  ) {   /* 嚙踝蕭嚙罵嚙瞌嚙稻嚙瞌嚙褐迎蕭 */
      ptr = top;               /* 嚙踝蕭嚙碾嚙踝蕭嚙罵嚙踝蕭嚙踝蕭 */
      top = top->next;         /* 嚙踝蕭嚙罵嚙踝蕭嚙請恬蕭嚙碾嚙磊嚙窯嚙瘢 */
      temp = ptr->data;        /* 嚙踝蕭嚙碼嚙踝蕭嚙� */
      free(ptr);               /* 嚙踝蕭嚙稷嚙窯嚙瘢嚙瞌嚙踝蕭嚙踝蕭 */
      return temp;             /* 嚙踝蕭嚙罵嚙踝蕭嚙碼 */
   }
   else return -1;
}
