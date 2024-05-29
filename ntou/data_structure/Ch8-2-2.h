/* 程式範例: Ch8-2-2.h */
#define MAX_VERTICES   10       /* 圖形的最大頂點數 */
struct Vertex {                 /* 圖形頂點結構宣告 */
   int data;                    /* 頂點資料 */
   struct Vertex *next;         /* 指下一個頂點的指標 */
};
typedef struct Vertex *Graph;   /* 圖形的新型態 */
struct Vertex head[MAX_VERTICES];/* 圖形頂點結構陣列 */
/* 抽象資料型態的操作函數宣告 */
extern void createGraph(int len, int *edge);
extern void printGraph();
extern void dfs(int vertex);
extern void bfs(int vertex);
