#include <iostream>
#include <string.h>
#include <string>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(){
	string uni1 = "0";
	string uni2 = "0";
	string uni3 = "0";
	string uni4 = "0";
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			for(int k=0;k<16;k++){
				for(int l=0;l<16;l++){
					if(i == 0)
						uni1 = "1";
					else if(i == 1)
						uni1 = "2";
					else if(i == 2)
						uni1 = "3";
					else if(i == 3)
						uni1 = "4";
					else if(i == 4)
						uni1 = "5";
					else if(i == 5)
						uni1 = "6";
					else if(i == 6)
						uni1 = "7";
					else if(i == 7)
						uni1 = "8";
					else if(i == 8)
						uni1 = "9";
					else if(i == 9)
						uni1 = "0";
					else if(i == 10)
						uni1 = "a";
					else if(i == 11)
						uni1 = "b";
					else if(i == 12)
						uni1 = "c";
					else if(i == 13)
						uni1 = "d";
					else if(i == 14)
						uni1 = "e";
					else if(i == 15)
						uni1 = "f";
					if(j == 0)
						uni2 = "1";
					else if(j == 1)
						uni2 = "2";
					else if(j == 2)
						uni2 = "3";
					else if(j == 3)
						uni2 = "4";
					else if(j == 4)
						uni2 = "5";
					else if(j == 5)
						uni2 = "6";
					else if(j == 6)
						uni2 = "7";
					else if(j == 7)
						uni2 = "8";
					else if(j == 8)
						uni2 = "9";
					else if(j == 9)
						uni2 = "0";
					else if(j == 10)
						uni2 = "a";
					else if(j == 11)
						uni2 = "b";
					else if(j == 12)
						uni2 = "c";
					else if(j == 13)
						uni2 = "d";
					else if(j == 14)
						uni2 = "e";
					else if(j == 15)
						uni2 = "f";
					if(k == 0)
						uni3 = "1";
					else if(k == 1)
						uni3 = "2";
					else if(k == 2)
						uni3 = "3";
					else if(k == 3)
						uni3 = "4";
					else if(k == 4)
						uni3 = "5";
					else if(k == 5)
						uni3 = "6";
					else if(k == 6)
						uni3 = "7";
					else if(k == 7)
						uni3 = "8";
					else if(k == 8)
						uni3 = "9";
					else if(k == 9)
						uni3 = "0";
					else if(k == 10)
						uni3 = "a";
					else if(k == 11)
						uni3 = "b";
					else if(k == 12)
						uni3 = "c";
					else if(k == 13)
						uni3 = "d";
					else if(k == 14)
						uni3 = "e";
					else if(k == 15)
						uni3 = "f";
					if(l == 0)
						uni4 = "1";
					else if(l == 1)
						uni4 = "2";
					else if(l == 2)
						uni4 = "3";
					else if(l == 3)
						uni4 = "4";
					else if(l == 4)
						uni4 = "5";
					else if(l == 5)
						uni4 = "6";
					else if(l == 6)
						uni4 = "7";
					else if(l == 7)
						uni4 = "8";
					else if(l == 8)
						uni4 = "9";
					else if(l == 9)
						uni4 = "0";
					else if(l == 10)
						uni4 = "a";
					else if(l == 11)
						uni4 = "b";
					else if(l == 12)
						uni4 = "c";
					else if(l == 13)
						uni4 = "d";
					else if(l == 14)
						uni4 = "e";
					else if(l == 15)
						uni4 = "f";
					printf("\u%s%s%s%s",uni1,uni2,uni3,uni4);
					cout << "" << uni1 << "" << uni2 << "" << uni3 << "" << uni4 << endl;
					///*delay(10);
					//getchar();
					//system("\u0000");
				}
			}
		}
	}
	return 0;
} 
