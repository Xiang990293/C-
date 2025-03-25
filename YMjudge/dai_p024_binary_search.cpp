#include<iostream>
#include <chrono>
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
	auto start = std::chrono::high_resolution_clock::now();

	int a,t;
	while(cin >> a >> t){
		int left = 0, right = 0, middle = 0;
		int data[a];
		left = 0;
		right = a-1;

		for(int i = 0; i<a; i++) cin >> data[a];

		while(left <= right){
			middle = (left+right)/2;
			if(t == data[middle]){
				break;
			}else if(t > data[middle]){
				left = middle + 1;
			}else{
				right = middle - 1;
			}
		}

		if(left <= right){
			cout << t << "位於資料中第" << middle + 1 << "個位置" << endl;
		}else{
			cout << t << "不存在" << endl;
		}

		

		// int b, s=-1;
		// for(int i=0;i<t;i++){
		// 	b = readint();
		// 	s=-1;
		// 	for(int j=0;j<a;j++) if(b==arr[j]){
		// 		s=j;
		// 		printf("在索引 ");
		// 		writeint(s);
		// 		printf("\n");
		// 		break;
		// 	}
		// 	if(s==-1){
		// 		printf("沒有搜尋到資料\n");
		// 	}
		// 	printf("------------\n");
		// }
	}
	auto finish = std::chrono::high_resolution_clock::now();
	printf("Elapsed time in seconds: %ld s\n", std::chrono::duration_cast<std::chrono::seconds>(finish-start).count());
}