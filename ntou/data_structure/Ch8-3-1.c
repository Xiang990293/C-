/* 程式範例: Ch8-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-2-2.h"
#include "createGraph.c"
int visited[MAX_VERTICES];        /* 走訪記錄陣列 */
/* 函數: 圖形的深度優先搜尋法 */ 
void dfs(int vertex) {
   Graph ptr;
   visited[vertex] = 1;           /* 記錄已走訪過 */
   printf("[V%d] ", vertex);      /* 顯示走訪的頂點值 */
   ptr = head[vertex].next;       /* 頂點指標 */
   while ( ptr != NULL ) {        /* 走訪至串列尾 */
      if ( visited[ptr->data] == 0 ) /* 是否走訪過 */
         dfs(ptr->data);          /* 遞迴走訪呼叫 */
      ptr = ptr->next;            /* 下一個頂點 */
   }
}
/* 主程式 */
int main() {
   int edge[14][2] = { {1, 2}, {2, 1}, /* 邊線陣列 */
                       {1, 3}, {3, 1},  
                       {3, 4}, {4, 3},
                       {3, 5}, {5, 3},
                       {4, 6}, {6, 4},
                       {5, 6}, {6, 5},
                       {6, 7}, {7, 6} };
   int i;  /* 設定走訪初值 */
   for ( i = 1; i < MAX_VERTICES; i++ ) visited[i] = 0;
   createGraph(14, &edge[0][0]);   /* 建立圖形 */
   printf("圖形G的鄰接矩陣內容:\n");
   printGraph();  /* 顯示圖形 */
   printf("圖形的深度優先走訪:\n");
   dfs(1);        /* 顯示走訪過程 */
   printf("\n");
   system("PAUSE");
   return 0; 
}
