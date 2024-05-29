/* 程式範例: Ch7-4-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-3.h"
#include "createBTree.c"
/* 函數: 二元樹的前序走訪 */
void preOrder(BTree ptr) {
   if ( ptr != NULL ) {     /* 終止條件 */
      /* 顯示節點內容 */
      printf("[%d]", ptr->data);
      preOrder(ptr->left);   /* 左子樹 */
      preOrder(ptr->right);  /* 右子樹 */
   }
}
/* 函數: 前序走訪顯示二元樹 */
void printPreOrder() {
   preOrder(head);  /* 呼叫前序走訪函數 */
   printf("\n");
} 
/* 主程式 */
int main() {
   /* 二元樹的節點資料 */
   int data[10] = {15, 16, 14, 18,12, 13, 17, 11, 19, 20};
   createBTree(10, data);     /* 建立二元樹 */
   printf("前序走訪的節點內容: \n");
   printPreOrder();   
   system("PAUSE");
   return 0; 
}
