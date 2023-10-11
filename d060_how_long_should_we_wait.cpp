#include<iostream>
using namespace std;

int main(){
	int m;
	while(cin >> m){
		cout << (60 - (m + 35)%60)%60 << endl;
	}
}