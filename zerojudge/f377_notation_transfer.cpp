#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

char current_char; // 現在正在處理的字符
// level = current_lay

char current_oper = 0; // 目前的運算符，預設為空，遇到非+-*/時也為空，只有遇到+-*/時，設為+-*/

int qsize; // 多次宣告的暫時變數
int i;

string temp = "";

string trans_to_postfix(string infix){
	int current_lay = 0; // 重設目前所在的副層級
	int previous_lay = 0; // 重設上一個總層級
	
	bool main_current_lay_fall = false; // main_current_lay是否減少
	int current_lay_full_count = 0;
	stack<char> opers[2]; // 建立一堆運算符號堆積(不只一個堆積)
	string temp_answer = "";

	stringstream s;
	s << infix;
	int lay;

	while(true){ // 處理該行
		s >> current_char;  // 直到該行無法處理為止
		if(s.fail()) break;
		main_current_lay_fall = false;

		switch(current_char){ // 先判斷優先級
			case '+':
				current_lay = 0;
				current_oper = '+';
				break;
			case '-':
				current_lay = 0;
				current_oper = '-';
				break;
			case '*':
				current_lay = 1;
				current_oper = '*';
				break;
			case '/':
				current_lay = 1;
				current_oper = '/';
				break;
			case '(':
				current_oper = 0;
				
				lay = 1;
				temp = ""
;				while(lay != 0){
					s >> current_char;
					if(current_char == '(') lay++;
					else if (current_char == ')') lay--;
					if(lay != 0) temp += string("") + current_char + " ";
				}
				temp_answer += trans_to_postfix(temp);
				break;
			default:
				current_oper = 1;
				current_lay_full_count++;
				temp_answer += string("") + (current_char) + " ";
				break;
		}

		if(previous_lay == current_lay && current_oper != 1){ // 遇到符號或括號，且優先級相等時，優先推送前面的已經有的同級運算
			qsize = opers[current_lay].size(); // 將優先級較低的運算推送回去
			for(i = 0; i < qsize; i++){
				temp_answer += string("") + opers[current_lay].top() + " ";
				opers[current_lay].pop();
			}
		}else if(previous_lay > current_lay && current_oper > 1){ //遇到符號，且優先級降低，優先推送前面的已經有的上級運算
			qsize = opers[previous_lay].size(); // 將優先級較高的運算推送回去
			for(i = 0; i < qsize; i++){
				temp_answer += string("") + opers[previous_lay].top() + " ";
				opers[previous_lay].pop();
			}

			qsize = opers[current_lay].size(); // 將優先級較高的運算推送回去
			for(i = 0; i < qsize; i++){
				temp_answer += string("") + opers[current_lay].top() + " ";
				opers[current_lay].pop();
			}
		}
		// cout << "pl=" << previous_lay << ", cl=" << current_lay << ", ch=" << current_char << ", " << temp_answer << endl;
		if(current_oper != 0 && current_oper != 1) opers[current_lay].push(current_oper);
		if(current_oper != 1) previous_lay = current_lay;
	}
	
	int remain_current_lay = current_lay + (main_current_lay_fall*current_lay_full_count)*2;
	for(int l = remain_current_lay; l >= 0; l--){
		int qsize = opers[l].size(); // 將優先級較低的運算推送回去
		for(int i = 0; i < qsize; i++){
			temp_answer += string("") + opers[l].top() + " ";
			opers[l].pop();
		}
	}

	return temp_answer;
}

int main(){
	stringstream s; // 處理一整行輸入
	string str; // 輸入時的整行字串儲存處

	string answer; // 最終轉換結果的儲存處

	// int q = 0;
	while(getline(cin, str)){ // 讀入新的一行
		// q++;
		// if(q == 27) cout << str << endl;
		answer = "";

		answer = trans_to_postfix(str);

		std::cout << answer << endl;
	}
}

/*
w - ( h - j ) * k
w h j - k * -
w h j - - k *
*/