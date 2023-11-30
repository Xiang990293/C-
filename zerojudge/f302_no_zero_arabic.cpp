#include<iostream>
#include<math.h>
#include<sstream>
using namespace std;

int main(){
	long long dec;
	long long nov;
	long long noz;
	string temp;
	while(cin >> temp) {
		int l = temp.length();
		noz = stoll(temp);
		for(int i=l-1; i>=0; i--) {
			if(temp[i]=='0') temp[i-1]+=1;
			cout << temp[i] << endl;
		}
	}
}