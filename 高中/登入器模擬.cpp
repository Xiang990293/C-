#include <iostream>
using namespace std;

int main () {
	//以下部分是輸入規則//
	cout << "在輸入名字前，請先閱讀以下輸入規則" << endl;
	cout << "1.輸入名字前，請先通知字數，以便系統方便存取" <<endl;
	cout << "2.密碼最多50字元" << endl;
	//規則結束//
	int n = 0;
	int i ;
	cout << "字數為: ";
	cin >> i;
	char name[i]={};
	int c;
	cout << "請輸入你的名字: ";
	for(n = 0;n <= i-1;n++)
		cin >> name[n];
	cout << "您所輸入的名字" << name << "是正確的嗎?輸入 0(是) 或 1(否) 用以確認> " << endl;
	cin >> c;
	while (c != 0) 
	{		
		cout << "字數為: ";
		cin >> i;
		cout << "請輸入你的名字> " ;
		for(n = 0;n <= i-1;n++)
			cin >> name[n];
		cout << "您所輸入的名字" << name << "是正確的嗎?輸入 0(是) 或 1(否) 用以確認> " << endl;
		cin >> c;
	}
	cout << "已確認!!" << endl;
	cout << "歡迎" << name << "登入本伺服器";
	return 0;
}

