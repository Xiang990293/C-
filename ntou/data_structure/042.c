#include <stdio.h>
#include <stdlib.h>
#include "stack_node.h"
/* 是否是運算子 */
int isOperator(char op) {
   switch ( op ) {
      case '+':
      case '-':
      case '*':
      case '/': return 1;      /* 是運算子 */
      default:  return 0;      /* 不是運算子 */
   }
}
/* 計算二元運算式的結果 */
int cal(int op,int operand1,int operand2) {
   switch ( (char) op ) {
      case '*': return ( operand2 * operand1 ); /* 乘 */
      case '/': return ( operand2 / operand1 ); /* 除 */
      case '+': return ( operand2 + operand1 ); /* 加 */
      case '-': return ( operand2 - operand1 ); /* 減 */
   }

   return 0;
}

/* 後序運算式的計算 */
int postfixEval(char *exp) {
   int operand1 = 0;              /* 第1個運算元變數 */
   int operand2 = 0;              /* 第2個運算元變數 */
   int pos = 0;                   /* 運算式字串索引 */
   /* 剖析運算式字串迴圈 */
   while ( exp[pos] != '\0' && exp[pos] != '\n' ) {
      if ( isOperator(exp[pos]) ) {  /* 是不是運算子 */
         /* 從堆疊取出兩個運算元 */
         operand1 = pop();
         operand2 = pop();
         /* 計算結果存回堆疊 */
         push(cal(exp[pos],operand2,operand1));
      }
      else  /* 這是運算元, 存入運算元堆疊 */
         push(exp[pos]-48);
      pos++;               /* 下一個字元 */
   } 
   return pop();   /* 傳回後序運算式的結果 */
}

/* 主程式 */
int main() {   
   char exp[100];                 /* 運算式的字串變數 */
   printf("請輸入後序運算式 ==> ");
   gets(exp);     /* 讀取運算式 */
   printf("運算式: %s = %d\n", exp, postfixEval(exp));
   system("PAUSE");

   return 0; 
}