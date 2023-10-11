#include<iostream>
using namespace std;

int main(){
	// int shopping, fare = 0;
	// cout << "輸入購物金額：";
	// cin >> shopping;
	// if(shopping < 800) fare = 100;
	// cout << "運費為" << fare << "元";

	// int money;
	// bool vip;
	// cout << "輸入消費金額：";
	// cin >> money;
	// cout << "輸入是否持有貴賓卡(0:無/1:有)：";
	// cin >> vip;
	// if(vip) money-=200;
	// cout << "應付金額為" << money << "元";

	// int num;
	// cout << "輸入一正整數：";
	// cin >> num;
	// cout << ((num%2)?"不為":"為") << "2的倍數";

	// char op;
	// cin >> op;
	// int num1, num2, ans;
	// cin >> num1 >> num2;
	// switch(op){
	// 	case '+':
	// 		ans = num1 + num2;
	// 		break;
	// 	case '-':
	// 		ans = num1 - num2;
	// 		break;
	// 	case '*':
	// 		ans = num1 * num2;
	// 		break;
	// 	case '/':
	// 		ans = num1 / num2;
	// 		break;
	// }
	// cout << num1 << op << num2 << "=" << ans << endl;

	// int month;
	// cout << "輸入農曆月份：";
	// cin >> month;
	// cout << month <<"月份為";
	// switch(month){
	// 	case 2 ... 4:
	// 		cout << "春";
	// 		break;
	// 	case 5 ... 7:
	// 		cout << "夏";
	// 		break;
	// 	case 8 ... 10:
	// 		cout << "秋";
	// 		break;
	// 	case 1:
	// 	case 11 ... 12:
	// 		cout << "冬";
	// 		break;
	// 	default:
	// 		cout << "err";
	// }
	// cout << "季";

	string id, pass;
	cout << "輸入帳號：";
	cin >> id;
	cout << "輸入密碼：";
	cin >> pass;
	if(id=="admin"&&pass=="password") cout << "歡迎您";
	else cout << "帳號或密碼錯誤";

	return 0;
}