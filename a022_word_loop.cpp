#include <iostream>
using namespace std;

int main(){
	string a="";
	while(cin>>a){
		bool isLoop = true;
		for(int i=0; i<a.length()/2; i++){
			if(a[i]!=a[a.length()-i-1]){
				cout << "no" << endl;
				isLoop = false;
				break;
			}
		}
		if(isLoop == true){
			cout << "yes" << endl;
		}
	}
}
