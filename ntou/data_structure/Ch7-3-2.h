/* 程式範例: Ch7-3-2.h */
#define MAX_LENGTH   16     /* 最大陣列尺寸 */
struct Node {               /* 二元樹的結構宣告 */
   int data;                /* 節點資料 */
   int left;                /* 指向左子樹的位置 */
   int right;               /* 指向右子樹的位置 */
};
typedef struct Node TreeNode;  /* 樹的節點新型態 */
TreeNode btree[MAX_LENGTH];    /* 二元樹結構陣列宣告 */
/* 抽象資料型態的操作函數宣告 */
extern void createBTree(int len, int *array);
extern void printBTree();
