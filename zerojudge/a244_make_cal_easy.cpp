#include<iostream>
using namespace std;

int main(){
	long n, a, b, c;
	while(cin>>n){
		a = b = c = 0;
		for(int i=0; i<n; i++){
			cin >> a >> b >> c;
			switch(a){
				case 1:
					cout << b+c << endl;
					break;
				case 2:
					cout << b-c << endl;
					break;
				case 3:
					cout << b*c << endl;
					break;
				case 4:
					cout << b/c << endl;
					break;
			}
		}
	}

	return 0;
}