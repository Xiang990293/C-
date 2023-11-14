#include<iostream>
using namespace std;

int dp[3010];
int dp_func(int num, int m){
	if(num == 0) return 1;
	if(dp[num]!=1 && num > 0) return dp[num];
	int sum=0, temp;
	for(int i=num-m-1; i>=0; i--){
		temp = dp_func(i, m);
		sum += (temp>=10000)?temp%10000:temp;
	}

	return (sum>=10000)?sum%10000:sum;
}

int main(){
	int N, M, sum;
	int combination;
	dp[0] = 1;
	while(cin >> N >> M){
		combination = 1;
		sum = 0;
		for(int i=0; i<3010; i++) dp[i] = 1;
		for(int i=0; i<=N; i++){
			dp[i] = dp_func(i, M);
			sum += (dp[i]>=10000)?(dp[i]%10000):dp[i];
			sum = (sum>=10000)?sum%10000:sum;
		}
		cout << sum << endl;
	}
}