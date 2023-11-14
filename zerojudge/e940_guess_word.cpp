#include<iostream>
using namespace std;

int main(){
	string answer, result, result_p;
	int n;
	char guess;
	while(cin >> answer){ // 先輸入正確答案，美輸入正確答案，就開始猜
		cin >> n; // 決定猜的數量
		for(int i=0; i<answer.length(); i++) result += '*'; // 用*充當未猜對的文字
		cout << result << endl; // 將目前的猜測結果回傳給使用者(測試用)
		for(int i=0; i<n; i++){ // 
			result_p = result;
			result = "";
			cin >> guess;
			for(int j=0; j<answer.length(); j++){
				if(answer[j] == guess) result += guess;
				else result += result_p[j];
			}

			cout << result << endl;
		}
	}
}