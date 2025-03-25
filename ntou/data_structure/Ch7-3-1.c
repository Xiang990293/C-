/* �{���d��: Ch7-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-1.h"
/* ���: �ϥΰ}�C�إߤG���� */ 
void createBTree(int len, int *array) {
   int level, i;             /* �𪺶��h */
   /* �M���}�C���� */
   for ( i = 0; i < MAX_LENGTH; i++ ) btree[i] = -1;
   btree[1] = array[1];      /* �إ߮ڸ`�I */
   /* �ϥΰj��s�W�G���𪺨�L�`�I */
   for ( i = 2; i < len; i++ ) {
      level = 1;                    /* �q���h1�}�l */
      while ( btree[level] != -1 ) { /* �O�_���l�� */
         if (array[i] > btree[level])/* �O���Υk�l�� */
            level = level * 2 + 1;   /* �k�l�� */
         else
            level = level * 2;       /* ���l�� */
      }
      btree[level] = array[i];       /* �x�s�`�I��� */
   }
}
/* ���: ��ܤG���� */
void printBTree() {
   int i;
   /* �ϥΰj����ܤG���𪺸`�I��� */
   for ( i = 1; i < MAX_LENGTH; i++ )
      if ( btree[i] != -1 )
         printf("[%d:%d]", i, btree[i]);
   printf("\n");
}
/* �D�{�� */
int main() {
   /* �G���𪺸`�I��� */
   int data[10] = { 0, 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   /* �إߤG���� */
   createBTree(10, data);
   printBTree();  /* ��ܤG���𪺸`�I��� */
   system("PAUSE");
   return 0; 
}
