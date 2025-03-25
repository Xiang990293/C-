/* �{���d��: createBTree.c */
/* ���: �إߤG���� */
void createBTree(int len, int *array) {
   int i; 
   /* �ϥΰj��H���J�覡�إ߾𪬵��c */
   for ( i = 0; i < len; i++ ) 
      insertBTreeNode(array[i]);
}
/* ���: �b�G���𴡤J�`�I(�Y�G���j�M�𪺸`�I���J) */
void insertBTreeNode(int d) {
   BTree newnode, current; /* �ثe�G����`�I���� */
   int inserted = 0; /* �O�_���J�s�`�I */
   /* �t�m�s�`�I���O���� */
   newnode = (BTree) malloc(sizeof(TNode));
   newnode->data = d;      /* �إ߸`�I���e */ 
   newnode->left = NULL;
   newnode->right = NULL;
   if ( isBTreeEmpty() )   /* �O�_�ŤG���� */
      head = newnode;      /* �إ߮ڸ`�I */
   else {  /* �O�d�ثe�G������� */
      current = head; 
      while( !inserted )    /* ����`�I�� */
         if ( current->data > newnode->data ) {
            /* �O�_�O�̥����l�`�I */
            if ( current->left == NULL ) {   
                current->left = newnode; /* �إ��쵲 */
                inserted = 1;
            } else current = current->left;/* ���l�� */
         }
         else {  /* �O�_�O�̥k���l�`�I */
            if ( current->right == NULL ) {
                current->right = newnode; /* �إ��쵲 */
                inserted = 1;
            } else current = current->right;/* �k�l�� */
         }
   }
}
/* ���: �ˬd�G����O�_�O�Ū� */
int isBTreeEmpty() {
   if ( head == NULL ) return 1;
   else                return 0; 
}
/* ���: ��ܤG���� */
void printBTree() {
   BTree ptr;
   printf("�ڸ`�I: [%d]\n", head->data);    
   ptr = head->left;      /* ���l�𪺫��� */
   printf("���l��: ");
   while ( ptr != NULL ) {
      printf("[%d]", ptr->data); /* ��ܸ`�I */
      ptr = ptr->left;    /* ���l�`�I */
   }
   printf("\n�k�l��: "); 
   ptr = head->right;     /* �k�l�𪺫��� */
   while ( ptr != NULL ) {
      printf("[%d]", ptr->data); /* ��ܸ`�I */
      ptr = ptr->right;   /* �k�l�`�I */
   }
   printf("\n"); 
} 
