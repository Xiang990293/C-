/* �{���d��: Ch7-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-2.h"
/* ���: �ϥΰ}�C�إߤG���� */ 
void createBTree(int len, int *data) {
   int level;                    /* �𪺶��h */
   int i, pos;                   /* -1�O����,1�O�k�� */
   for ( i = 0; i < MAX_LENGTH; i++ ) {  
      /* �M�����c�}�C   */
      btree[i].data=0; btree[i].left=btree[i].right=-1;
   }
   btree[0].data = data[0];      /* �إ߾�ڸ`�I */
   for ( i = 1; i < len; i++ ) { /* �إ߸`�I���j�� */
      btree[i].data = data[i];   /* �إ߸`�I���e */
      level = 0; pos = 0;    
      while ( pos == 0 ) {/* �ϥΰj�����O���Υk�l�� */
         if ( data[i] > btree[level].data )
            /* �k��O�_���U�@���h */
            if ( btree[level].right != -1 )
               level = btree[level].right;
            else pos = -1;        /* �O�k�� */
         else /* ����O�_���U�@���h */
            if ( btree[level].left != -1 )
               level = btree[level].left;
            else pos = 1;         /* �O���� */
      }
      if (pos==1) btree[level].left = i;/* �쵲���l�� */
      else        btree[level].right= i;/* �쵲�k�l�� */
   }
}
/* ���: ��ܤG���� */
void printBTree() {
   int i;
   printf("    ��  ���  �k\n");
   for ( i = 0; i < MAX_LENGTH; i++ )
      if ( btree[i].data != 0 )     /* �O�_�O�𪺸`�I */
         printf("%2d:[%2d] [%2d] [%2d]\n",i,
         btree[i].left,btree[i].data,btree[i].right);
}
/* �D�{�� */
int main() {
   /* �G���𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   /* �إߤG���� */
   createBTree(9, data);
   printBTree();  /* ��ܤG���𪺸`�I��� */
   system("PAUSE");
   return 0;   
}
