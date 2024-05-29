/* 程式範例: Ch7-3-3.h */
struct Node {             /* 二元樹的節點宣告 */
   int data;              /* 儲存節點資料 */ 
   struct Node *left;     /* 指向左子樹的指標 */
   struct Node *right;    /* 指向右子樹的指標 */          
};
typedef struct Node TNode;  /* 二元樹節點的新型態 */
typedef TNode *BTree;       /* 二元樹鏈結的新型態 */
BTree head = NULL;          /* 二元樹根節點的指標 */
/* 抽象資料型態的操作函數宣告 */
extern void createBTree(int len, int *array);
extern void insertBTreeNode(int d);
extern int isBTreeEmpty();
extern void printBTree(); 
extern void inOrder(BTree ptr);
extern void printInOrder();
extern void preOrder(BTree ptr);
extern void printPreOrder();
extern void postOrder(BTree ptr);
extern void printPostOrder();
