#include<iostream>
using namespace std;

int main(){
	int w;
	while(cin >> w){
		cout << w - (w>50) << endl;
	}
}