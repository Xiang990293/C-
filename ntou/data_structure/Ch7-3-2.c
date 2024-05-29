/* 程式範例: Ch7-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-2.h"
/* 函數: 使用陣列建立二元樹 */ 
void createBTree(int len, int *data) {
   int level;                    /* 樹的階層 */
   int i, pos;                   /* -1是左樹,1是右樹 */
   for ( i = 0; i < MAX_LENGTH; i++ ) {  
      /* 清除結構陣列   */
      btree[i].data=0; btree[i].left=btree[i].right=-1;
   }
   btree[0].data = data[0];      /* 建立樹根節點 */
   for ( i = 1; i < len; i++ ) { /* 建立節點的迴圈 */
      btree[i].data = data[i];   /* 建立節點內容 */
      level = 0; pos = 0;    
      while ( pos == 0 ) {/* 使用迴圈比較是左或右子樹 */
         if ( data[i] > btree[level].data )
            /* 右樹是否有下一階層 */
            if ( btree[level].right != -1 )
               level = btree[level].right;
            else pos = -1;        /* 是右樹 */
         else /* 左樹是否有下一階層 */
            if ( btree[level].left != -1 )
               level = btree[level].left;
            else pos = 1;         /* 是左樹 */
      }
      if (pos==1) btree[level].left = i;/* 鏈結左子樹 */
      else        btree[level].right= i;/* 鏈結右子樹 */
   }
}
/* 函數: 顯示二元樹 */
void printBTree() {
   int i;
   printf("    左  資料  右\n");
   for ( i = 0; i < MAX_LENGTH; i++ )
      if ( btree[i].data != 0 )     /* 是否是樹的節點 */
         printf("%2d:[%2d] [%2d] [%2d]\n",i,
         btree[i].left,btree[i].data,btree[i].right);
}
/* 主程式 */
int main() {
   /* 二元樹的節點資料 */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   /* 建立二元樹 */
   createBTree(9, data);
   printBTree();  /* 顯示二元樹的節點資料 */
   system("PAUSE");
   return 0;   
}
