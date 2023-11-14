	#include <iostream>
	using namespace std;

	int main(){
		// int i, sum=0;
		// sum = sum + 1;
		// sum = sum + 3;
		// sum = sum + 5;
		// sum = sum + 7;
		// sum = sum + 9;
		// sum = sum + 11;
		// sum = sum + 13;
		// sum = sum + 15;
		// sum = sum + 17;
		// sum = sum + 19;
		// cout << "1+3+5+7+9+11+13+15+17+19=" << sum << endl;

		// int i, sum=0;
		// for(i=1; i<=19; i+=2) sum += i;
		// cout << "1+3+5+7+9+11+13+15+17+19=" << sum << endl;

		// int a, i=0;
		// double j = 1.0, sum;
		// cout << "輸入1~9的整數";
		// cin >> a;
		// sum = a;
		// cout << a;
		// cout.setf(ios::fixed);
		// for(int i=1; i<=10; i++){
		// 	j = j/10+1;
		// 	sum += a*j;
		// 	cout.precision(i);
		// 	cout << "+" << a*j;
		// }
		// cout << "=" << sum << endl;

		// int num, remainder;
		// cout << "輸入一正整數";
		// cin >> num;
		// cout << num << "的顛倒輸出為";
		// while(num > 0){
		// 	remainder = num % 10;
		// 	cout << remainder;
		// 	num /= 10;
		// }

		// int a,b;
		// int divisor, dividend, remainder, gcd;
		// cout << "輸入兩個正整數(空白隔開)";
		// cin >> a >> b;
		// dividend = a;
		// divisor = b;
		// do{
		// 	remainder = dividend % divisor;
		// 	dividend = divisor;
		// 	divisor = remainder;
		// }while(remainder != 0);

		// gcd = dividend;
		// cout << "(" << a << "," << b << ")=" << gcd;

		// int num=1, password;
		// do{
		// 	cout << "輸入密碼:" ;
		// 	cin >> password;
		// 	if(password == 20230901){
		// 		cout << "密碼輸入正確" << endl;
		// 		break;
		// 	}else{
		// 		cout << "密碼輸入錯誤" << endl;
		// 	}
		// 	num++;
		// }while(num <= 3);

		int sum = 0;
		int i;
		for(i=0; i<=50; i++){
			if(i % 2 == 0) continue;
			sum += i;
		}
		cout << "1到50之間的奇數和=" << sum;
	}