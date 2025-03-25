
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int isOperator(char op) {
   switch ( op ) {
      case '+':
      case '-':
      case '*':
      case '/': return 1;      
      default:  return 0;      
   }
}

int cal(int op,int operand1,int operand2) {
   switch ( (char) op ) {
      case '*': return ( operand2 * operand1 ); 
      case '/': return ( operand2 / operand1 ); 
      case '+': return ( operand2 + operand1 ); 
      case '-': return ( operand2 - operand1 ); 
   }
}

int postfixEval(char *exp) {
   int operand1 = 0;              
   int operand2 = 0;              
   int pos = 0;                   
   
   while ( exp[pos] != '\0' && exp[pos] != '\n' ) {
      if ( isOperator(exp[pos]) ) {  
         
         operand1 = pop();
         operand2 = pop();
         
         push(cal(exp[pos],operand2,operand1));
      }
      else  
         push(exp[pos]-48);
      pos++;               
   } 
   return pop();   
}

int main() {   
   char exp[100];                 
   printf("請輸入後序運算式 ==> ");
   gets(exp);     
   printf("運算式: %s = %d\n", exp, postfixEval(exp));
   system("PAUSE");
   return 0; 
}
