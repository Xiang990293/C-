#include<iostream>
using namespace std;

int main(){
	int count;
	while(cin >> count) {
		int a[count][2] = {};
		for(int i=0; i<count; i++) {
			cin >> a[i][0];
			a[i][0] -= 1;
		}

		bool teleported = 0;
		int max = 0;
		int counter = 0;
		for(int i=0; i<count || (!teleported && i == count); ) {
			teleported = 0;
			if(a[i][1] != 0) {
				if(counter > max) max = counter;
				counter = 0;
				i++;
				continue;
			}else {
				a[i][1] = 1;
				counter++;
				i = a[i][0];
				teleported = 1;
			}
		}
		cout << max << endl;
	}
}