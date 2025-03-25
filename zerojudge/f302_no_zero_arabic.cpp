#include<iostream>
#include<math.h>
#include<sstream>
using namespace std;

int main(){
	long long dec;
	int carry;
	string temp;
	while(cin >> temp) {
		carry = 0;
		int l = temp.length();
		for(int i=l-1; i>=0; i--) {
			temp[i] = char(temp[i] + carry);
			carry = 0;
			if(temp[i]=='9') {
				carry=1;
				temp[i] = '0';
			}
		}
		if(carry == 1) temp = "1" + temp;
		dec = 0;
		l = temp.length();
		for(int i=0; i<l; i++){
			dec = dec*9+(temp[i]-48);
		}
		cout << dec << endl;
	}
}