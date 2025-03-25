#include<iostream>
using namespace std;

int dp[3000];
int dp_func(int num, int m){
	if(num <= 0) return 1;
	if(dp[0] >= num) return dp[num];
	dp[num] = (dp_func(num - 1, m) + dp_func(num - m - 1, m)) % 10000;
	dp[0] = num;
	
	return dp[num];
}

int fact[3000];
int factorial(int x){
	if(x == 0) return 1;
	if(x == 1) return 1;
	if(fact[0] >= x) return fact[x];

	fact[x] = (x * fact[x-1]) % 10000;
	fact[0] = x;

	return fact[x];
}

// 萬位數以上，不會影響鉛位數以下加法，可以在dp中直接截斷
// 目前

int main(){
	dp[0] = 0;
	fact[0] = 0;
	// N = points, M = period
	int points, period, sum;
	int combination;
	while(cin >> points >> period){
		cout << dp_func(points, period) << endl;
		// combination = 1;
		// sum = 0;
		// for(int i=0; i<3010; i++) dp[i] = 1;
		// for(int i=0; i<=points; i++){
		// 	dp[i] = dp_func(i, period);
		// 	sum += (dp[i]>=10000)?(dp[i]%10000):dp[i];
		// 	sum = (sum>=10000)?sum%10000:sum;
		// }
		// cout << sum << endl;
	}
}