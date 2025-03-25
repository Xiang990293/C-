#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;

const int num[] = {0,1,2,3,4,5,6,7,8,9};
const char operater[] = {'+','$','*','/','%'};
const char symble[] = {'(',')'};

// string sub_form(string s, int i){
// 	int start=0, stop=0;
// 	for(start=i-1; s[start]!='+'&&s[start]!='$'&&s[start]!='*'&&s[start]!='/'&&s[start]!='%'&&s[start]!='#';start--){}
// 	for(stop=i+1; s[stop]!='+'&&s[stop]!='$'&&s[stop]!='*'&&s[stop]!='/'&&s[stop]!='%'&&s[stop]!='#';stop++){}

// 	return s.substr(start+1, stop-start-1);
// }

// string ans(string s){
// 	return s.substr(1,s.length()-2);
// }

// string math_logic(string iformula){
// 	// iformula = simplify_sign(iformula);

// 	//jump into parentheses first
// 	for(int i=0; i<iformula.length(); i++){
// 		if(iformula[i]=='('){
// 			int substart = i+1;
// 			int sublength = 0;
// 			for(int laycount=1; laycount!=0; sublength++){
// 				switch(iformula[substart+sublength]){
// 					case '(':{
// 						laycount++;
// 						break;
// 					}
// 					case ')':{
// 						laycount--;
// 						break;
// 					}
// 				}
// 			}
// 			iformula = iformula.replace(substart-1, sublength+1, ans(math_logic('#'+iformula.substr(substart,sublength-1)+'#')));
// 		}
// 	}

// 	//actaully do the math
// 	for(int i=0; i<iformula.length(); i++){
// 		switch(iformula[i]){
// 			case '*':{ //multiply
// 				string subed_str = sub_form(iformula,i);
// 				iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)*num_back(iformula,i)));
// 				i=0;
// 			}break;

// 			case '/':{ //divide
// 				if(num_back(iformula,i)){
// 					string subed_str = sub_form(iformula,i);
// 					iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string((long double)num_front(iformula,i)/(long double)num_back(iformula,i)));
// 					i=0;
// 				}else{
// 					iformula = "#0#";
// 					i=0;
// 				}
// 			}break;

// 			case '%':{ //find remainder
// 				if(num_back(iformula,i)){
// 					string subed_str = sub_form(iformula,i);
// 					iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)%num_back(iformula,i)));
// 					i=0;
// 				}else{
// 					iformula = "#0#";
// 					i=0;
// 				}
// 			}break;
// 		}
// 	}
	
// 	for(int i=0; i<iformula.length(); i++){
// 		switch(iformula[i]){
// 			case '+':{ //addition
// 				string subed_str = sub_form(iformula,i);
// 				iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)+num_back(iformula,i)));
// 				i=0;
// 			}break;

// 			case '$':{ //subtraction
// 				string subed_str = sub_form(iformula,i);
// 				iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)-num_back(iformula,i)));
// 				i=0;
// 			}break;
// 		}
// 	}
// 	return iformula;
// }

struct Operand{
	string operand;

	Operand(string a){
		operand = a;
	}

	Operand(){
		operand = "0";
	}
};

struct Operator{
	char operators;

	Operator(char op){
		switch(op){
			case '+':{
				operators = '+';
				break;
			}
			case '-':{
				operators = '-';
				break;
			}
			case '*':{
				operators = '*';
				break;
			}
			case '/':{
				operators = '/';
				break;
			}
			case '%':{
				operators = '%';
				break;
			}
			default:{ // if formula got wrong
				operators = '+';
				break;
			}
		}
	}
};

struct formula{
	Operand a;
	Operand b;
	Operator op;

	formula(Operand a1, Operand b1, Operator op1){
		a = a1;
		b = b1;
		op = op1;
	}
};

int main(){
	stringstream s;
	string strResult;
	string formula;
	int a, b;
	while(getline(cin, strResult)){
		s.clear();
		s.str("");
		s << strResult;
		formula = "";
		while(true){
			s >> a >> formula >> b;
			if(s.fail()) break;
			cout << a << formula << b << endl;
		}
	}
	
	return 0;
}

// 利用遞迴處理順序問題
// 利用getline來讀取數字，不用for查