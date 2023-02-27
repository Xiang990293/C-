#include<iostream>
#include<math.h>
using namespace std;

const long long Largest = 100;
const long long large_prime = 5761455;
long long count[large_prime] = {0};

long long dp[100]={0};
long long fact(int a){
	dp[1] = 1;
	if(dp[a]!=0) return dp[a];
	else for(int i=2; i<a; i++) dp[a] = fact(a-1) * a;
	return dp[a];
}

int main(){
	int index=1;
	int a,b;
	count[1]=1;
	for(long long i=2; i<Largest; i++){
		if((fact(i-1)+1)/i%1==0) index++;
		count[i] = index;
	}
	while(cin>>a>>b){
		cout << count[b]-count[a] << endl;
	}
} 
