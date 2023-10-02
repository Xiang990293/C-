#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int num = 1;
	cout.fill('0');
	cout << setw(4) << num;
	cout.setf(ios::left);
	cout << setw(4) << num;
}