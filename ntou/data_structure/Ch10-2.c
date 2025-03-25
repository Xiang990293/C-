/* 程式範例: Ch10-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      11          /* 最大的陣列尺寸 */
/* 函數: 循序搜尋法 */ 
int sequential(int *data, int count, int target) {
   int i;                        /* 變數宣告 */ 
   for ( i = 0; i < count; i++ ) /* 搜尋迴圈 */
      /* 比較是否是鍵值 */
      if ( data[i] == target )
         return i;
   return -1;             
}
/* 主程式 */ 
int main() {
   int data[MAX_LEN] =          /* 搜尋的陣列 */
         {13, 4, 26, 28, 1, 31, 34, 29, 51, 30};
   int i, index, target, c;
   printf("原始陣列: "); 
   for ( i = 0; i < MAX_LEN; i++ )
       printf("[%d]", data[i]); /* 顯示陣列元素 */
   printf("\n");
   target = 0;
   while ( target != -1 ) {
      printf("請輸入搜尋值(-1結束) ==> ");
      scanf("%d", &target);
      /* 呼叫循序搜尋法的搜尋函數 */ 
      index = sequential(data, MAX_LEN, target);
      if (index != -1)
          printf("搜尋到鍵值: %d(%d)\n", target, index);
      else
          printf("沒有搜尋到鍵值: %d\n", target);
   }
   system("PAUSE");
   return 0;  
}
