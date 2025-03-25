#include<iostream>
using namespace std;

int main(){
	float grade, sum=0;
	while(cin >> grade){
		sum += grade;
		for(int i=0; i<3; i++){
			cin >> grade;
			sum += grade;
		}
		sum/=4;
		switch(((int)sum)){
			case 81 ... 100:
				cout << "學習狀態優良" << endl;
				break;
			case 71 ... 80:
				cout << "學習狀態普通" << endl;
				break;
			case 60 ... 70:
				cout << "學習狀態待加強" << endl;
				break;
			case 0 ... 59:
				cout << "你已被期中預警" << endl;
				break;
			default:
				cout << "請重新輸入" << endl;
				break;
		}
		sum = 0;
		cout << "\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a" << endl;
	}


	return 0;
}