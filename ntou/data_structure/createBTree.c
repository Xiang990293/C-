/* 程式範例: createBTree.c */
/* 函數: 建立二元樹 */
void createBTree(int len, int *array) {
   int i; 
   /* 使用迴圈以插入方式建立樹狀結構 */
   for ( i = 0; i < len; i++ ) 
      insertBTreeNode(array[i]);
}
/* 函數: 在二元樹插入節點(即二元搜尋樹的節點插入) */
void insertBTreeNode(int d) {
   BTree newnode, current; /* 目前二元樹節點指標 */
   int inserted = 0; /* 是否插入新節點 */
   /* 配置新節點的記憶體 */
   newnode = (BTree) malloc(sizeof(TNode));
   newnode->data = d;      /* 建立節點內容 */ 
   newnode->left = NULL;
   newnode->right = NULL;
   if ( isBTreeEmpty() )   /* 是否空二元樹 */
      head = newnode;      /* 建立根節點 */
   else {  /* 保留目前二元樹指標 */
      current = head; 
      while( !inserted )    /* 比較節點值 */
         if ( current->data > newnode->data ) {
            /* 是否是最左的子節點 */
            if ( current->left == NULL ) {   
                current->left = newnode; /* 建立鏈結 */
                inserted = 1;
            } else current = current->left;/* 左子樹 */
         }
         else {  /* 是否是最右的子節點 */
            if ( current->right == NULL ) {
                current->right = newnode; /* 建立鏈結 */
                inserted = 1;
            } else current = current->right;/* 右子樹 */
         }
   }
}
/* 函數: 檢查二元樹是否是空的 */
int isBTreeEmpty() {
   if ( head == NULL ) return 1;
   else                return 0; 
}
/* 函數: 顯示二元樹 */
void printBTree() {
   BTree ptr;
   printf("根節點: [%d]\n", head->data);    
   ptr = head->left;      /* 左子樹的指標 */
   printf("左子樹: ");
   while ( ptr != NULL ) {
      printf("[%d]", ptr->data); /* 顯示節點 */
      ptr = ptr->left;    /* 左子節點 */
   }
   printf("\n右子樹: "); 
   ptr = head->right;     /* 右子樹的指標 */
   while ( ptr != NULL ) {
      printf("[%d]", ptr->data); /* 顯示節點 */
      ptr = ptr->right;   /* 右子節點 */
   }
   printf("\n"); 
} 
