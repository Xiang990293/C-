#include <iostream>
using namespace std;

int main(){
	float a = 1.2345678901234567890f;
	double b;
	cout.precision(20);
	cout.setf(ios::fixed);
	cout << "a=" << a << '\n';

	a = 12.34567928314208984375f;
	cout << "a=" << a << '\n';
}