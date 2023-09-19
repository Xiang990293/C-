#include<iostream>
using namespace std;

int main(){
	int time_t;
	while(cin >> time_t){
		cout << (time_t + 9)%24 << endl;
	}
}