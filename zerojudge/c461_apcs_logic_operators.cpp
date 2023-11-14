#include<iostream>
using namespace std;

int main(){
	int a_t, b_t;
	bool a, b, r;
	while(cin >> a_t >> b_t >> r){
		a = a_t!=0;
		b = b_t!=0;
		if((a&b)==r) cout << "AND" << endl;
		if((a|b)==r) cout << "OR" << endl;
		if(a^b==r) cout << "XOR" << endl;
		if(((a&b)!=r)&&((a|b)!=r)&&((a^b)!=r)) cout << "IMPOSSIBLE" << endl;
	}
}