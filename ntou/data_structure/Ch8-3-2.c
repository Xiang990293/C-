/* 程式範例: Ch8-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "Ch8-2-2.h"
#include "createGraph.c"
int visited[MAX_VERTICES];        /* 走訪記錄陣列 */
/* 函數: 圖形的寬度優先搜尋法 */ 
void bfs(int vertex) {
   Graph ptr;
   /* 處理第一個頂點 */
   enqueue(vertex);               /* 將頂點存入佇列 */
   visited[vertex] = 1;           /* 記錄已走訪過 */
   printf("[V%d] ", vertex);      /* 顯示走訪的頂點值 */
   while ( !isQueueEmpty() ) {    /* 佇列是否已空 */
      vertex = dequeue();         /* 將頂點從佇列取出 */
      ptr = head[vertex].next;    /* 頂點指標 */
      while ( ptr != NULL ) {     /* 走訪至串列尾 */
         if ( visited[ptr->data]==0 ) {/* 是否走訪過 */
            enqueue(ptr->data);   /* 存入佇列 */
            visited[ptr->data] = 1; /* 記錄已走訪過 */
            /* 顯示走訪的頂點值 */
            printf("[V%d] ", ptr->data);
         }
         ptr = ptr->next;         /* 下一個頂點 */
      }
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
   createGraph(14, &edge[0][0]);     /* 建立圖形 */
   printf("圖形G的鄰接矩陣內容:\n");
   printGraph();  /* 顯示圖形 */
   printf("圖形的寬度優先走訪:\n");
   bfs(1);        /* 顯示走訪過程 */
   printf("\n");
   system("PAUSE");
   return 0; 
}
