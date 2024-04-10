
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int isOperator(char op) {
   switch ( op ) {
      case '(':
      case ')':
      case '+':
      case '-':
      case '*':
      case '/': return 1;      
      default:  return 0;      
   }
}

int priority(char op) {
   switch ( op ) {    
      case '*':
      case '/': return 3;
      case '+':
      case '-': return 2;
      case '(': return 1;
      default:  return 0;
   }
}

void postfix(char *infix) {
   int op, doit;                  
   int pos = 0;                   
   
   while ( infix[pos] != '\0' && infix[pos] != '\n' ) {
      if ( isOperator(infix[pos]) ) { 
         if ( isStackEmpty() || 
              infix[pos] == '(' )    
                 push(infix[pos]);
         else if ( infix[pos] == ')' ) { 
               doit = 1;
               while ( doit ) {
                  
                  op = pop();
                  if ( op != '(' )
                     printf("%c", op);  
                  else 
                  doit = 0;
               }
            }
            else {  
               doit = 1;
               while ( doit &&  
                 !isStackEmpty()) {
                 op = pop();  
                 if (priority(infix[pos])<=priority(op))
                    printf("%c", op);   
                 else {
                    push(op);  
                    doit = 0;
                 }   
               } 
               push(infix[pos]);
            }
      } else  printf("%c", infix[pos]);   
      pos++;
   }  
   while ( !isStackEmpty() ) 
      printf("%c", pop());    
   printf("\n"); 
}

int main() {   
   char exp[100];              
   printf("請輸入中序運算式 ==> ");
   gets(exp);         
   printf("後序運算式: ");
   postfix(exp);      
   system("PAUSE");
   return 0; 
}
