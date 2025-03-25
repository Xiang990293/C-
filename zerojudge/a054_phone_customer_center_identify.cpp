#include<iostream>
using namespace std;

const char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const int num[26]=   { 1 , 0 , 9 , 8 , 7 , 6 , 5 , 4 , 9 , 3 , 2 , 2 , 1 , 0 , 8 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 1 , 3 , 2 , 0 };

int main(){
	string a="";
	while(cin >> a){
		int x=0;
		for(int i=8; i>0; i--){
			x += (a[8-i]-48)*i;
		}
		x %= 10;

        int c=10-(a[8]-48);
        for(int i=0; i<26; i++){
            if((num[i]%10+x)%10==c%10){
                cout << alpha[i];
            }
        }
        cout << endl;
	}
}
