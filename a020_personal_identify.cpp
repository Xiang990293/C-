#include <iostream>
using namespace std;

const char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const int num[26]=   { 1 , 10, 19, 28, 37, 46, 55, 64, 39, 73, 82, 2 , 11, 20, 48, 29, 38, 47, 56, 65, 74, 83, 21, 3 , 12, 30};
//each alphabet stand for 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33 but 10a+b=>a+9b
int main(){
	string a="";
	while(cin >> a){
		int x=0;
		for(int i=0; i<26; i++){
			if(a[0] == alpha[i]){
				x=num[i];
				break;
			}
		}
		for(int i=8; i>0; i--){
			x = x + (a[9-i]-48)*i;
		}
		x = x + (a[9]-48);
		
		if(x%10==0){
			cout << "real" << endl;
		}else{
			cout << "fake" << endl;
		}
	}
}
