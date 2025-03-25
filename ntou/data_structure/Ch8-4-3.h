/* 程式範例: Ch8-4-3.h */
#define MAX_VERTICES   9          /* 最大頂點數加一 */
struct Edge {                     /* 圖形邊線結構宣告 */
   int from;                      /* 開始頂點 */
   int to;                        /* 終點頂點 */
   int weight;                    /* 權值 */
   struct Edge *next;             /* 指下一條邊線 */
};
typedef struct Edge *EdgeList;    /* 邊線的結構新型態 */
EdgeList first = NULL;            /* 邊線串列開始指標 */
int vertex[MAX_VERTICES];         /* 檢查迴圈的頂點陣列 */
/* 抽象資料型態的操作函數宣告 */
extern void createEdge(int len, int *edge);
extern void minSpanTree();
extern void addSet(int from, int to);
extern int isSameSet(int from, int to);
