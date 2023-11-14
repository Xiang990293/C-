#include<iostream>
using namespace std;

int main(){
	int n, c;
	while(cin >> n >> c){
		if(n==0) cout << "OK!" << endl;
		else if(c==0) cout << "OK!" << endl;
		else if(n%c==0) cout << "OK!" << endl;
		else cout << n%c << endl;
	}
}