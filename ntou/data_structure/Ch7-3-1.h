/* 程式範例: Ch7-3-1.h */
#define MAX_LENGTH   16     /* 最大陣列尺寸 */
int btree[MAX_LENGTH];      /* 二元樹的陣列宣告 */
/* 抽象資料型態的操作函數宣告 */
extern void createBTree(int len, int *array);
extern void printBTree();
