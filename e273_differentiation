#include<iostream>
#include<cstdio>
using namespace std;

inline uint_fast16_t readint(){
	uint_fast64_t a=0;
	char c='0';
	do{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return a;
}
inline void writeint(uint_fast64_t d){
	if(d==0){
		putchar(48);
		return;
	}
	unsigned int len=0;
	char n[20];
	do{
		n[len]=d%10+48;
		len++;
		d/=10;
	}while(d>0);
	for(int i=len-1;i>=0;i--) putchar(n[i]);
}

int main(){
	uint_fast16_t n=0;
	
	while(n = readint()){
		uint_fast16_t a(0);
		
		if(n==1){
			a = readint();
			writeint(0);
			putchar(13);
		}else{
			for(uint_fast16_t i=n-1; i>0; i--){
				a = readint();
				writeint(a*i);
				putchar((i==1)?13:32);
			}
			readint();
		}
	}
}
