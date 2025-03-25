#include<iostream>
using namespace std;

int main(){
	int year = 20;
	float multiplier = 1;
	for(int i=1; i<=year; i++){
		multiplier *= (1 + 0.01*i);
	}
	cout << 50000 * multiplier << endl;
}