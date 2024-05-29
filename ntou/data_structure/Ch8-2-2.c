/* 程式範例: Ch8-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-2-2.h"
#include "createGraph.c"
/* 主程式 */
int main() {
   int edge[16][2] = { {1, 2}, {2, 1},  /* 邊線陣列 */
                       {1, 3}, {3, 1},
                       {2, 3}, {3, 2},
                       {2, 4}, {4, 2},
                       {3, 5}, {5, 3},
                       {4, 5}, {5, 4},
                       {4, 6}, {6, 4},
                       {5, 6}, {6, 5} };
   createGraph(16, &edge[0][0]);   /* 建立圖形 */
   printf("圖形G的鄰接串列內容:\n");
   printGraph();  /* 顯示圖形 */
   system("PAUSE");
   return 0; 
}
