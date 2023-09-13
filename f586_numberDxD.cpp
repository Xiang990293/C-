#include <math.h>
#include <iostream>
using namespace std;

int square_free_integer(int n){
	if(n==1) return 1;

	int count;
	for(int i = 2; i <= n; i ++){
		if(n % i == 0 && n / i % i == 0) return 0;
		if(n % i == 0){
			n /= i;
			count++;
		}
	}

	int r = -1;
	for(int i=0; i<count-1; i++){
		r*=-1;
	}

	return r;
}

int main(){
	int n, c;
	while(cin >> c){
		for(int i = 0; i < c; i++){
			cin >> n;
			cout << square_free_integer(n) << endl;
		}
	}
	return 0;
}
