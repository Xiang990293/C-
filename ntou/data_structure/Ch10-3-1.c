/* 程式範例: Ch10-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      15          /* 最大的陣列尺寸 */
/* 函數: 二元搜尋法 */ 
int binary(int *data, int low, int high, int target) {
   int middle;                   /* 宣告變數 */
   if (low > high)               /* 遞迴的終止條件 */
      return -1;
   else {  /* 取得中間索引 */
      middle = (low + high) / 2;
      if ( target == data[middle] ) /* 找到 */
         return middle;   /* 傳回索引值 */
      else if ( target < data[middle] )/* 前半部分 */
              return binary(data,low,middle-1,target);
           else   /* 後半部分 */
              return binary(data,middle+1,high,target);
   }
}
/* 主程式 */ 
int main() {
   int data[MAX_LEN] =          /* 搜尋的陣列 */
         {1, 4, 6, 8, 11, 21, 24, 26, 28, 34, 49, 51, 60};
   int i, index, target, c;
   printf("原始陣列: "); 
   for ( i = 0; i < MAX_LEN; i++ )
       printf("[%d]", data[i]); /* 顯示陣列元素 */
   printf("\n");
   target = 0;
   while ( target != -1 ) {
      printf("請輸入搜尋值(-1結束) ==> ");
      scanf("%d", &target);
      /* 呼叫二元搜尋法的搜尋函數 */ 
      index = binary(data, 0, MAX_LEN-1, target);
      if (index != -1)
          printf("搜尋到鍵值: %d(%d)\n", target, index);
      else
          printf("沒有搜尋到鍵值: %d\n", target);
   }
   system("PAUSE");
   return 0;  
}
