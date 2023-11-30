#include<iostream>
using namespace std;

int main(){
	int count;
	while(cin >> count){
		for(int i=count-1; i>=0; i--){
			for(int j=0; j<count; j++){
				if(j>=i) cout << "*";
				else cout << "_";
			}
			cout << endl;
		}
	}
}