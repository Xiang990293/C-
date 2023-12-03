#include <iostream>
#include <string>
using namespace std;

int main(){
	int decimal_num;
	string binary_num;

	while(cin >> decimal_num){
		binary_num = "";
		while(decimal_num>1){
			binary_num = to_string(decimal_num%2) + binary_num;
			decimal_num = decimal_num/2;
		}
		binary_num = to_string(decimal_num%2) + binary_num;

		cout << binary_num << endl;
	}
	
	return 0;
}