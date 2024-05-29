/* 程式範例: createGraph.c */
/* 函數: 使用邊線陣列建立圖形 */ 
void createGraph(int len, int *edge) {
   Graph newnode, ptr;           /* 頂點指標 */
   int from, to;                 /* 邊線的起點和終點 */
   int i;
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      head[i].data = i;          /* 設定頂點值 */
      head[i].next = NULL;       /* 清除圖形指標 */
   }
   for ( i = 0; i < len; i++ ) { /* 讀取邊線的迴圈 */
      from = edge[i*2];          /* 邊線的起點 */
      to = edge[i*2+1];          /* 邊線的終點 */
      /* 配置新頂點的記憶體 */
      newnode = (Graph)malloc(sizeof(struct Vertex));
      newnode->data = to;       /* 建立頂點內容 */
      newnode->next = NULL;     /* 設定指標初值 */
      ptr = &(head[from]);      /* 指標陣列的頂點指標 */
      while ( ptr->next != NULL ) /* 走訪至串列尾 */
         ptr = ptr->next;         /* 下一個頂點 */
      ptr->next = newnode;        /* 插入結尾 */
   }
}
/* 函數: 顯示圖形 */
void printGraph() {
   Graph ptr;
   int i;
   /* 使用迴圈顯示圖形 */
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      ptr = head[i].next;               /* 頂點指標 */
      if ( ptr != NULL ) {  /* 有使用的節點 */ 
         printf("頂點V%d =>", head[i].data);/* 頂點值 */
         while ( ptr != NULL ) {        /* 走訪顯示 */
            printf("V%d ", ptr->data);  /* 頂點內容 */
            ptr = ptr->next;            /* 下一個頂點 */
         }
         printf("\n");
      }   
   }
}
