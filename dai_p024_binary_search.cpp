#include<iostream>
#include<vector>
using namespace std;

// int bs(int s, int e, int *a, int middle){
// 	return 0;
// }

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

int main(){
	int a,t;
	while(a = readint()){
		t = readint();
		vector<int> arr;
		int temp;
		for(int i=0;i<a;i++){
			temp = readint();
			arr.push_back(temp);
		}
		int b, s=-1;
		for(int i=0;i<t;i++){
			b = readint();
			s=-1;
			for(int j=0;j<a;j++) if(b==arr[j]){
				s=j;
				printf("在索引 ");
				writeint(s);
				printf("\n");
				break;
			}
			if(s==-1){
				printf("沒有搜尋到資料\n");
			}
			printf("------------\n");
		}
	}
}