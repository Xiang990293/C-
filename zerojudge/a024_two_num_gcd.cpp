#include <iostream>
using namespace std;

/* this question seems to be same to a738, see the solution with recursive method using euclidean algorithm*/

int main(){
	int a,b;
	int max,min;
	int container;
	while(cin >> a >> b){
		if(a==b){
			cout << a << endl;
		}else if(a!=0 && b!=0){
			if(a > b){
					max = a;
					min = b;
				}else{
					max = b;
					min = a;
				}
			int gcd = 1;
			while(max%min!=0){
				//cout << "max:" << max << ",min:" << min << " " << max%min << endl;
				max = max%min;
				gcd = max;
				if(min > max){
					container = min;
					min = max;
					max = container;
				}else{
					max = max;
					min = min;
				}
			}
			cout << gcd << endl;
		}else{
			cout << 0 << endl;
		}
	}
}
