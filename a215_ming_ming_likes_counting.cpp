#include<iostream>
#include<math.h>
using namespace std;

long long check(int n, int m){
	if(n>m) return 1;
	if(n==m) return 2;
	if(n*m<0){
		if(m>0) return 2*abs(n)+1+check(abs(n)+1,m);
		if(m==0) return 2*abs(n)+1;
		if(m<0) return 2*abs(n)+1-check(1,n)+check(1,m);
	}else{
		long long x=(-1+sqrt(1+4*(n*n-n+2*m)))/2;
		return ceil(x) - n + 1 + floor(1+(x)-ceil(x));
	}
}

int main(){
	long long n, m;
	// for(n=-30000; n<=30000; n++) for(m=n-1000; m<=n+1000; m++) if(check(n, m) < 0) cout << n << " " << m << endl;
	n=23360, m=23652;
	long long x=(-1+sqrt(1+4*(n*n-n+2*m)))/2;
	cout << ceil(x) - n + 1 + floor(1+(x)-ceil(x)) << endl;
	cout << ceil(x)<< " " << n << " " << floor(1+(x)-ceil(x)) << endl;
	// while(cin>>n>>m){
	// 	cout << check(n,m) << endl;
	// }
}