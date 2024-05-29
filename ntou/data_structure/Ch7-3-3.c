/* 程式範例: Ch7-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-3.h"
#include "createBTree.c"
/* 主程式 */
int main() {
   /* 二元樹的節點資料 */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBTree(9, data);     /* 建立二元樹 */
   printf("二元樹是空的: %d\n", isBTreeEmpty());
   printf("二元樹的節點內容: \n");
   printBTree();
   system("PAUSE");
   return 0; 
}
