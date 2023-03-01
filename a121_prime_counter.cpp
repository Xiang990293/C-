#include<iostream>
#include<math.h>
using namespace std;

int check(int a, int b){
	if(a==b){
		if(a==1) return 0;
		else {
			for(int j=2; j<=ceil(sqrt(a)); j++){
				if(a%j==0){
					return 0;
				}
				return 1;
			}
		}	
	}else{
		int count=0;
		for(int i=a; i<=b; i++){
			int test=0;
			for(int j=2; j<=ceil(sqrt(i)); j++){
				if(i%j==0){
					test++;
					break;
				}
			}
			if(test==0) count++;
		}
		return count;
	}
}

int main(){
	
	int a,b;
	
	while(cin>>a>>b){
		cout << check(a,b) << endl;
	}
}
