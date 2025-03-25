#define HEAD <iostream>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include HEAD
using namespace std;



#define pi 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798
#define HOUR 24
#define CHINESE "中文"
#define MYWAIT cout << "請稍後..." << endl;
#define PRINTSTAR \
	for(i=1;i<=3;i++) {\
		for(j=1;j<=i;j++) cout << '*';\
		cout << endl;\
	}
#define LEAP(y) \
	if((y) % 400 == 0 || ((y) % 100 != 0 && (y) % 4 == 0)) cout << "西元" << y <<  "年為閏年" << endl;\
	else cout << "西元" << y <<  "年為平年" << endl;

#define F(x) 2*x
#define MYNAME(name) cout << "我的名字是" << name << endl;


int main(){
	// string name[3] = {"剪刀","石頭","布"};
	// string result[3][3] = {{"平手","你輸了","你贏了"},{"你贏了","平手","你輸了"},{"你輸了","你贏了","平手"}};
	// char input;
	// int people;
	// int computer;
	// srand((unsigned)time(NULL));
	// while(1) {	cout << "出拳(0:" << name[0] << ",1:" << name[1] << ",2:" << name[2] << ",Enter:離開)";
	// 	input=getche();
	// 	if(input=='\r') {
	// 		cout << "\n遊戲結束\n";
	// 		break;
	// 	}
	// 	if(input < '0' || input > '2') {
	// 		cout << "error, 請輸入正確的字符" << endl;
	// 		continue;
	// 	}
	// 	people=input-48;
	// 	computer=rand()%3;
	// 	cout << "\n你出拳：" << name[people] << endl;
	// 	cout << "電腦出拳：" << name[computer] << endl;
	// 	cout << "結果：" << result[people][computer] << endl;
	// }

	int i, j;
	cout << HOUR << endl;
	cout << CHINESE << endl;
	MYNAME("Mike");
	PRINTSTAR;
	LEAP(2012);
	MYWAIT;
	cout << "F(2)=" << F(2) << endl;
}