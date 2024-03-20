#include <iostream>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <complex>
#include <regex>
#include <sstream>
#include <algorithm>
#include <graphics.h>
using namespace std;

int main()
{
	// stringstream s;
	// string str;
	// while(getline(cin, str)){
	// 	s.str("");
	// 	s.clear();
	// 	s << str;
	// 	while(true){
	// 		s >> str;
	// 		if(s.fail()) break;
	// 		cout << str << endl;
	// 	}
	// }

	// string a = "";
	// cout << (a == "") << endl;
	// a += char(0);
	// cout << (a == "") << endl;
	// a = "";
	// a += "";
	// cout << (a == "") << endl;

	int a, b;
	while(cin >> a >> b){
		cout << a << endl;
		a <<= b;
		cout << a << endl;
	}
}