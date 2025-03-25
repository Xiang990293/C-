#include<iostream>
#include<math.h>
using namespace std;

bool check_prime(int a){
	if (a == 1) return false;
	if (a == 0) return false;
	for(int j=2; j<=ceil(sqrt(a)); j++){
		if(a%j==0) return false;
	}
	return true;
}

int main(){
	
	int a;
	
	while(cin>>a){
		cout << check_prime(a) << " ";
	}
	cout << endl;
}
