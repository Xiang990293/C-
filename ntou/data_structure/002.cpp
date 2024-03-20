#include<iostream>
using namespace std;

unsigned long long int factorial(int start_num){
	if (start_num == 1) return 1;
	if (start_num == 0) return 1;
	if (start_num > 34) return -1;

	return (unsigned long long int)start_num * factorial(start_num-1);
}

int main(){
	long int input=0;
	while(cin >> input){
		if (input == -1) break;

		cout << factorial(input) << endl;
	}
}