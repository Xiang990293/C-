/* 程式範例: Ch10-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      13          /* 最大的陣列尺寸 */
/* 函數: 插補搜尋法的遞迴函數 */ 
int interSearch(int *data,int key,int left,int right) {
   int nextGuess;                /* 下一個可能索引 */
   int offset;                   /* 索引位移 */
   int range;                    /* 鍵值範圍 */
   int index_range;              /* 索引範圍 */
   int temp;
   if ( data[left] == key )      /* 找到了 */
      return left;
   else if ( left == right ||    /* 沒有找到 */
           data[left] == data[right] )
         return -1;
      else {
        index_range = right - left;/* 計算索引範圍 */
        /* 計算鍵值範圍 */
        range = data[right] - data[left];
        offset = key - data[left]; /* 計算鍵值位移 */
        temp = ( offset * index_range ) / range;
        nextGuess = left + temp;   /* 下一個可能索引 */
        if ( nextGuess == left )   /* 是否己試過 */
          nextGuess++;
        if ( key < data[nextGuess] )
          /* 左邊部分遞迴呼叫插補搜尋 */
          return interSearch(data,key,left,nextGuess-1);
        else
          /* 右邊部分遞迴呼叫插補搜尋 */
          return interSearch(data,key,nextGuess,right);
      }
}
/* 函數: 插補搜尋法 */
int interpolation(int *data, int n, int key) {
   if ( key < data[0] || key > data[n-1] )
      return -1;                       /* 沒有找到 */
   else
      return interSearch(data, key, 0, n-1); /* 遞迴呼叫 */
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
      /* 呼叫插補搜尋法的搜尋函數 */ 
      index = interpolation(data, MAX_LEN, target);
      if (index != -1)
          printf("搜尋到鍵值: %d(%d)\n", target, index);
      else
          printf("沒有搜尋到鍵值: %d\n", target);
   }
   system("PAUSE");
   return 0;  
}
