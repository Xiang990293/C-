#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	string name = "Leo";
	int age = 19;
	string blood = "AB";
	float height = 171.2;
	double money = 3141592653589793238;
	cout.precision(4);
	cout 
	<< "1234567890123456789012345678901234567890" 
	<< "1234567890\n"
	<< "我的名字叫" << name
	<< "\t今年" << age << "歲\n"
	<< "血型是" << blood << "\t身高"
	<< setw(7) << height << "公分\t";

	cout.setf(ios::scientific);
	cout.precision(10);
	cout << "銀行存款" << money << "元";
	return 0;
}