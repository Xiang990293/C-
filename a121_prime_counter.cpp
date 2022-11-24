#include<iostream>
#include<math.h>
using namespace std;

const int large_prime = 5761455;
int prime[large_prime] = {0};

int counter(int from, int to){
	int count=0;
	bool cancal=0;
	for(int i=0; i<large_prime; i++){
		if(prime[i]>=from&&!cancal) cancal=1;
		if(prime[i]>=to&&cancal){
			if(prime[i]==to) count++;
			return count;
		}else if(cancal){
			count++;
		}
	}

	return 0;
}

int dpa[100][3] = {0};
int index_for_dp=0;
int dp(int start, int stop){
	if (start==stop) return 0;
	for(int i=0; i<index_for_dp&&index_for_dp>0; i++){
		if (dpa[i][0]==start&&dpa[i][1]==stop) return dpa[i][2];
	}
	dpa[index_for_dp][0]=start;
	dpa[index_for_dp][1]=stop;
	dpa[index_for_dp][2]=counter(start,stop);
	index_for_dp++;
	return dpa[index_for_dp-1][2];
}

int main(){
	int index=2;
	int a,b;
	prime[0]=2;
	prime[1]=3;
	while(cin>>a>>b){
		for(int i=5; i<b; i++){
			int j;
			for(j=2; j<=sqrt(i)&&i%j!=0; j++){}
			if(j>sqrt(i)){
				prime[index] = i;
				index++;
			}
		}
		cout << dp(a,b) << endl;
	}
} 
