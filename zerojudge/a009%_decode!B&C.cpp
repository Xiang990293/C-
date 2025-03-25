#include <iostream>
#include <math.h>
using namespace std;

class a1z26_bit {
	int num;
	char alpha;
	bool isnum;
	const string list_alpha = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	a1z26_bit(int a){
		num = a;
		alpha = '-';
		isnum = true;
	}

	a1z26_bit(char a){
		alpha = a;
		num = -1;
		isnum = false;
	}

	a1z26_bit trans(a1z26_bit a){
		if (a.isnum){
			return a1z26_bit(list_alpha[a.num]);
		}else{
			return a1z26_bit(((char) a.alpha)-64);
		}
	}

	a1z26_bit operator>>(a1z26_bit& a){
		
	}
};

int main(){
	int mode;
	while(cin >> mode){
		a1z26_bit a;
		while (mode==0 && cin >> a) {
		}
		while (mode==1){ 
			
		}
    }
    return 0;
}
