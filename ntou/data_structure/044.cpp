#include <stdio.h>
#include <stdlib.h>

int hanoiTower(int dishs,int peg1,int peg2,int peg3) {
   if ( dishs == 1)             
     printf("盤子 %d 從 %d 移到 %d\n", dishs, peg1, peg3);
   else {
     hanoiTower(dishs - 1,peg1,peg3,peg2); 
     printf("盤子 %d 從 %d 移到 %d\n", dishs, peg1, peg3);
     hanoiTower(dishs - 1,peg2,peg1,peg3); 
   }
}

int main() {
   hanoiTower(4,1,2,3);          
   system("PAUSE");
   return 0; 
}