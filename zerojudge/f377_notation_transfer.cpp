#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

string alter_opers = "*/";
string nor_opers = "+-";
string parent = "()";

string parentheses(string strm){
	return "";
}

string postix_notation(char a, char op, char b){
	string re = "";
	re += a+" ";
	re += b+" ";
	re += op;
	return re;
}

int main(){
	stringstream s;
	string str;
	char num;
	char temp;
	string answer;
	int index = 0;
	int level = 0;
	int previous_level = 0;
	char current_oper = ' ';

	while(getline(cin, str)){ // 讀入新的一行
		stack<char> opers[100];
		answer = "";
		s.str("");
		s.clear();
		s << str;
		int laycount = 0;
		index = 0;
		bool laycount_fall = false;
		int lay_full_count = 0;

		while(true){ // 處理該行
			index++;
			s >> temp;  // 直到該行無法處理為止
			if(s.fail()) break;
			laycount_fall = false;

			switch(temp){ // 先判斷優先級
				case '+':
					level = 0;
					current_oper = '+';
					lay_full_count = 0;
					break;
				case '-':
					level = 0;
					current_oper = '-';
					lay_full_count = 0;
					break;
				case '*':
					level = 1;
					current_oper = '*';
					lay_full_count = 0;
					break;
				case '/':
					level = 1;
					current_oper = '/';
					lay_full_count = 0;
					break;
				case '(':
					if(index == 1) index--;
					current_oper = 0;
					lay_full_count = 0;
					laycount++;
					break;
				case ')':
					current_oper = 0;
					laycount_fall = true;
					lay_full_count++;
					break;
				default:
					current_oper = 0;
					lay_full_count++;
					if(index != 1) answer += string(" ") + temp;
					else answer += temp;
					break;
			}

			int current_level = level + laycount*2;
			if(previous_level > current_level && current_oper != 0){
				opers[current_level].push(current_oper);
				for(int l = previous_level; l > current_level; l--){
					int qsize = opers[l].size(); // 將優先級較低的運算推送回去
					for(int i = 0; i < qsize; i++){
						answer += string(" ") + opers[l].top();
						opers[l].pop();
					}
				}
			}
			else if(previous_level == current_level && current_oper != 0){ // 當優先級相等時，優先推送前面的已經有的同級運算
				int qsize = opers[current_level].size(); // 將優先級較低的運算推送回去
				for(int i = 0; i < qsize; i++){
					answer += string(" ") + opers[current_level].top();
					opers[current_level].pop();
				}
			}else if(previous_level == current_level && current_oper == 0){
				int qsize = opers[current_level].size(); // 將優先級較低的運算推送回去
				for(int i = 0; i < qsize; i++){
					answer += string(" ") + opers[current_level].top();
					opers[current_level].pop();
				}
			}
			opers[current_level].push(current_oper);

			if(laycount_fall) laycount--;
			previous_level = current_level;

			cout << "current_level=" << current_level << ", oper=" << current_oper << "\t, laycount=" << laycount << ", " << answer << endl;
		}

		int remain_lay = level + (laycount+laycount_fall*lay_full_count)*2;
		for(int l = remain_lay; l >= 0; l--){
			int qsize = opers[l].size(); // 將優先級較低的運算推送回去
			for(int i = 0; i < qsize; i++){
				answer += string(" ") + opers[l].top();
				opers[l].pop();
			}
		}

		std::cout << answer << endl;
	}
}