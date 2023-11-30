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

	int a = 0;
	while(cin >> a){
		cout << ", dec=" << a;
		string nov;
		int dec = a;
		while(dec != 0){
			nov += char(dec%9+48);
			dec /= 9;
		}
		if(dec==0) nov = "0";
		reverse(nov.begin(),nov.end());
		cout << ", nov=" << nov << endl;
		for(int i = 0;;) ;
	}
}