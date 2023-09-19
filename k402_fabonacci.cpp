#include<iostream>
using namespace std;

long long F[32767] = {};
bool S[32767] = {};
long long Fabonacci(int n){
	if(n==0) return 0;
	if(n==1) return 0;
	if(n==2) return 1;
	if(S[n]){
		return F[n];
	}else{
		F[n] = Fabonacci(n-1) + Fabonacci(n-2);
		S[n] = true;
		return F[n];
	}

	return 0;
}

int main(){
	F[1] = 0;
	F[2] = 1;
	int n=0;
	while(cin >> n){
		cout << Fabonacci(n) << endl;
	}
}