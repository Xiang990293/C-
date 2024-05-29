/* 程式範例: Ch7-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-1.h"
/* 函數: 使用陣列建立二元樹 */ 
void createBTree(int len, int *array) {
   int level, i;             /* 樹的階層 */
   /* 清除陣列元素 */
   for ( i = 0; i < MAX_LENGTH; i++ ) btree[i] = -1;
   btree[1] = array[1];      /* 建立根節點 */
   /* 使用迴圈新增二元樹的其他節點 */
   for ( i = 2; i < len; i++ ) {
      level = 1;                    /* 從階層1開始 */
      while ( btree[level] != -1 ) { /* 是否有子樹 */
         if (array[i] > btree[level])/* 是左或右子樹 */
            level = level * 2 + 1;   /* 右子樹 */
         else
            level = level * 2;       /* 左子樹 */
      }
      btree[level] = array[i];       /* 儲存節點資料 */
   }
}
/* 函數: 顯示二元樹 */
void printBTree() {
   int i;
   /* 使用迴圈顯示二元樹的節點資料 */
   for ( i = 1; i < MAX_LENGTH; i++ )
      if ( btree[i] != -1 )
         printf("[%d:%d]", i, btree[i]);
   printf("\n");
}
/* 主程式 */
int main() {
   /* 二元樹的節點資料 */
   int data[10] = { 0, 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   /* 建立二元樹 */
   createBTree(10, data);
   printBTree();  /* 顯示二元樹的節點資料 */
   system("PAUSE");
   return 0; 
}
