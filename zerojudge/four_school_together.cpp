#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	while(cin >> a >> b >> c){
		int i;
		for(i=1; i<=a; i++){
			if(i%b==0){
				a = a + c;
			}
		}
		cout << i-1 <<endl;
	}
}
