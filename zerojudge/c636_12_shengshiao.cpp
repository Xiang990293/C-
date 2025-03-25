#include<iostream>
using namespace std;

string year[12] = {"鼠","牛","虎","兔","龍","蛇","馬","羊","猴","雞","狗","豬"};

int main(){
	int y;
	while(cin >> y){
		if(y>0) cout << year[(y-1)%12] << endl;
		else cout << year[(120+y)%12] << endl;
	}
}