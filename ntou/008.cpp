#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	// int num1, num2;
	// int result, answer;
	// char op;

	// srand((unsigned) time(NULL));

	// cout << "請回答下列四則運算題：";
	// num1 = 1 + rand()%100;
	// num2 = 1 + rand()%100;
	// switch(1 + rand()%4){
	// 	case 1:
	// 		op = '+';
	// 		result = num1 + num2;
	// 		break;
	// 	case 2:
	// 		op = '-';
	// 		result = num1 - num2;
	// 		break;
	// 	case 3:
	// 		op = '*';
	// 		result = num1 * num2;
	// 		break;
	// 	case 4:
	// 		op = '/';
	// 		result = num1 / num2;
	// 		break;
	// }
	
	// cout << num1 << op << num2 << "= ?" << endl;
	// cin >> answer;
	// if(answer == result) cout << "答對" << endl;
	// else cout << "答錯" << endl;

	int num1, num2;
	int result, answer;
	char op;

	srand((unsigned) time(NULL));
	
	int counter = 1;
	for(int i=counter; i>=0; --i){
		cout << "請回答下列四則運算題：";
		num1 = 1 + rand()%100;
		num2 = 1 + rand()%100;
		switch(1 + rand()%4){
			case 1:
				op = '+';
				result = num1 + num2;
				break;
			case 2:
				op = '-';
				result = num1 - num2;
				break;
			case 3:
				op = '*';
				result = num1 * num2;
				break;
			case 4:
				op = '/';
				result = num1 / num2;
				break;
		}
		
		cout << num1 << op << num2 << "= ?" << endl;
		cin >> answer;
		if(answer == result) cout << "答對" << endl;
		else cout << "答錯，是" << result << endl;

		char conti;
		if(i==0){
			cout << "是否繼續？(y/n)";
			cin >> conti;
			if(conti == 'n' || conti == 'N') break;
			else{
				cout << "請問要再練習幾題?";
				cin >> counter;
				i = counter;
			}
		}
	}
}