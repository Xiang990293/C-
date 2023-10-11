#include<iostream>
#include<cctype>
#include<regex>
using namespace std;

int main(){
	string s;
	int sum;
	regex pattern("[\\W!_0-9]");
	while(cin >> s){
		if(s=="0") break;
		sum = 0;
		if(regex_search(s, pattern)){
			cout << "Fail" << endl;
			continue;
		}
		for(char &c : s){
			c = toupper(c);
			sum += (c-64);
		}
		cout << sum << endl;

	}
}