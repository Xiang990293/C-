#include<iostream>
using namespace std;

int main(){
	int money, remain_hour;
	float hour;
	money = 0;
	hour = 5.5;
	remain_hour = (int)hour;
	switch(remain_hour){
		case 6 ... 2147483647:
			money += (remain_hour-5)*60;
			remain_hour = 5;
		case 4 ... 5:
			money += (remain_hour-3)*50;
			remain_hour = 3;
		case 2 ... 3:
			money += (remain_hour-1)*40;
			remain_hour = 1;
		case 1:
			money += 30;
			break;
		default:
			cout << "error" << endl;
			break;
	}
	cout << "停車時間 " << hour << " 的停車費總計為: " << money << endl;
}