#include<iostream>
using namespace std;

string pairchanger(string a){
	for(int i=2*(n-1)-1-1; i>=0; i--){
		btemp = binpos >> i;
		cout << btemp << endl;
		binpos -= btemp << i;
	}
}

void parenthesespairer(int n){
	if(n==0) return;
	if(n==1){
		cout << "()" << endl;
		return;
	}
	if(n==2){
		cout << "(())\n()()" << endl;
		return;
	}
	if(n>13) return; //break for too large num
	
	//do in 3<=n<=13
	
	///set initial state as a
	string a="",b="";
	for(int i=0; i<n; i++){
		a+="(";
		b+=")";
	}
	a+=b;
	
	//making binpos, position with binary storing
	unsigned int binpos = 0b0, btemp=0b0;
	for(int i=2*(n-1)-1; i>0; i--){
		binpos <<= 1;
		binpos += (a[i]=='('&& a[i+1]==')');
	}
	
	pairchanger(string a); 
	
	return;
}

int main(){
	int n=0;
	while(cin>>n) parenthesespairer(n);
} 
