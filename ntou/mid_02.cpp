#include<iostream>
#include<cmath>
using namespace std;

int main(){
	float get;
	while(cin >> get){
		int temp = ceil(get/10000);
		switch(temp){
			case 0 ... 52:
				get = get*0.05 - 0;
				break;
			case 53 ... 117:
				get = get*0.12 - 36400;
				break;
			case 118 ... 235:
				get = get*0.2 - 130000;
				break;
			case 236 ... 440:
				get = get*0.3 - 365000;
				break;
			case 441 ... 11000:
				get = get*0.4 - 805000;
				break;
			case 11001 ... 2147483647:
				get = get*0.45 - 1305000;
				break;
				cout << "輸入錯誤" << endl;
				get = -1;
				break;
		}
		cout << (int)get << endl;
	}
}