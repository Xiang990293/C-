#include<iostream>
#include<math.h>
using namespace std;

int main(){
	
	int a,b;
	
	while(cin>>a>>b){
		int count=0;
		for(int i=a; i<=b; i++){
			for(int j=2; j<=10000||j<=sqrt(i); j++){
				if(i==j) count++;
				else if(i%j==0) break;
			}
		}
		cout << count << endl;
	}
}
