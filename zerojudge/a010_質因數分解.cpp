#include <math.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		for(int i = 2; i <= n; i ++){
			int count = 0;
			while(n % i == 0){
				n /= i;
				count++;
			}
			
			if(count >= 2){
				cout<<i<<"^"<<count;
				if(n !=1)
					cout<<" * ";
			}else if(count == 1){
				cout<<i;
				if(n !=1)
					cout<<" * ";
			}
			
		}
	}
	return 0;
}

 
