/* 程式範例: Ch8-2-1.h */
#define MAX_VERTICES 7           /* 最大頂點數加一 */
int graph[MAX_VERTICES][MAX_VERTICES];/* 圖形陣列 */
/* 抽象資料型態的操作函數宣告 */
extern void createGraph(int len, int *edge);
extern void printGraph();
