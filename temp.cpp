#include<iostream>
#include<vector>
#include<math.h>
#include<complex>
#include<regex>
#include<sstream>
using namespace std;

int main(){
	stringstream s;
	string str, a, b, c;
	float sum, temp;
	char se;
	while(getline(cin, str)){
		s.str("");
		s.clear();
		s << str;
		while(true){
			s >> a >> b >> c;
			if(s.fail()) break;
			cout << a << " " << b << " " << c << endl;
		}
	}
}