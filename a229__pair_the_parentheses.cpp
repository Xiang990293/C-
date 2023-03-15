#include<iostream>
using namespace std;

string ParenthesesPairing(int n,bool inside){
	if(n==0) return "";
	if(n==1) return "()";
	
	string re="";
	re=ParenthesesPairing(n-1,true);
	
	for(int i=n-1; i>0; i--){
		re += (inside==true)?"(":"";
		re += ParenthesesPairing(n-i,false)+ParenthesesPairing(i,false);
		re += (inside==true)?")":"";
		re += "\n";
	}
	
	return re;
}

int main(){
	int n;
	while(cin >> n){
		cout << ParenthesesPairing(n,false) << endl;
	}
}
