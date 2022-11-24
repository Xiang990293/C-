#include<iostream>
using namespace std;

int abs(int a){
	if(a<0) return -1*a;
	else return a;
}

int main(){
	string a="";
	while(cin>>a){
		for(int i=0; i<a.length()-1; i++){
			cout << abs((int)a[i+1] - (int)a[i]);
		}
		cout << endl;
	}
}