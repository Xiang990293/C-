#include<iostream>
using namespace std;

int main(){
	int hh, mm;
	while(cin >> hh >> mm){
		mm+=hh*60;
		cout << ((mm>=450&&mm<1020)?"At":"Off") << " School" << endl;
	}
}