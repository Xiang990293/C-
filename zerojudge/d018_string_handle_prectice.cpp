#include<iostream>
#include<sstream>
using namespace std;

int main(){
	stringstream s;
	string str;
	int num;
	float sum, temp;
	char se;
	while(getline(cin, str)){
		s.str("");
		s.clear();
		s << str;
		sum = 0;
		while(true){
			s >> num;
			if(s.fail()) break;
			s >> se;
			s >> temp;
			sum += ((num%2)?1:-1)*temp;
		}
		cout << sum << endl;
	}
}