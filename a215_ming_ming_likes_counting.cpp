#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n, m;
	while(cin>>n>>m){
		int x=(-1+sqrt(1+4*(n*n-n+2*m)))/2;
		cout << ceil(x) - n + 1 + floor(1-ceil(x)+(x)) << endl;
	}
}