#include<iostream>
#include<sstream>
using namespace std;

int main(){
	stringstream s;
	string str;
	while(getline(cin, str)){
		s.str("");
		s.clear();
		s << str;
	}
}