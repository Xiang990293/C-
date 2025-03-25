#include<iostream>
#include<cstdio>
#include<numeric>
using namespace std;

// uint_fast16_t ==> int

inline int gcd(int a, int b){
	return b>0?gcd(b, a%b):a;
}

inline int lcm(int a, int b){
	return a/gcd(a,b)*b;
}

inline int readint(){
	int a=0;
	char c='0';
	do{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return a;
}
inline void writeint(int d){
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

int find_min_possible(int a1, int a2, int a3){
	int j, i = a2*a3;
	while(j%a1!=1) j+=i;
	return j;
}

int main(){
	int a1=0;
	
	while(a1 = readint()){
		int b1 = readint();
		int a2 = readint();
		int b2 = readint();
		int a3 = readint();
		int b3 = readint();
		
		//more efficient, but unaccurate...
		int m = lcm(a1, lcm(a2, a3));
		int factor = find_min_possible(a1, a2, a3)*b1 + find_min_possible(a2, a1, a3)*b2 + find_min_possible(a3, a2, a1)*b3;
		

		putchar(13); //in ASCII, 13 == "\n", 32 == " "

		//more accurate, but slow...
		int i=a3+b3;
		
		while (1){
			if (i%a1==b1 && i%a2==b2){
				cout << i << endl;
				break;
			}
			i+=a3;
		}
	}
}
