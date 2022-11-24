#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

const int num[] = {0,1,2,3,4,5,6,7,8,9};
const char operater[] = {'+','$','*','/','%'};
const char symble[] = {'(',')'};

int num_front(string s, int i){
	string a = "";
	int j=0,l=0;
	for(j=i-1,l=1; s[j]!='+'&&s[j]!='$'&&s[j]!='*'&&s[j]!='/'&&s[j]!='%'&&s[j]!='#';j--){
		l++;
	}
	
	return stoi(s.substr(j+1,l));
}

int num_back(string s, int i){
	string a = "";
	int j=0,l=0;
	for(j=i+1,l=1; s[j]!='+'&&s[j]!='$'&&s[j]!='*'&&s[j]!='/'&&s[j]!='%'&&s[j]!='#';j++){
		l++;
	}
	
	return stoi(s.substr(i+1,l));
}

string sub_form(string s, int i){
	int start=0, stop=0;
	for(start=i-1; s[start]!='+'&&s[start]!='$'&&s[start]!='*'&&s[start]!='/'&&s[start]!='%'&&s[start]!='#';start--){}
	for(stop=i+1; s[stop]!='+'&&s[stop]!='$'&&s[stop]!='*'&&s[stop]!='/'&&s[stop]!='%'&&s[stop]!='#';stop++){}

	return s.substr(start+1, stop-start-1);
}

string ans(string s){
	return s.substr(1,s.length()-2);
}

string math_logic(string iformula){
	for(int i=0; i<iformula.length(); i++){
		if(iformula[i]=='('){
			int substart = i+1;
			int sublength = 0;
			for(int laycount=1; laycount!=0; sublength++){
				switch(iformula[substart+sublength]){
					case '(':{
						laycount++;
						break;
					}
					case ')':{
						laycount--;
						break;
					}
				}
			}
			iformula = iformula.replace(substart-1, sublength+1, ans(math_logic('#'+iformula.substr(substart,sublength-1)+'#')));
		}
	}
	for(int i=0; i<iformula.length(); i++){
		switch(iformula[i]){
			case '*':{
				string subed_str = sub_form(iformula,i);
				iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)*num_back(iformula,i)));
				i=0;
			}break;

			case '/':{
				if(num_back(iformula,i)){
					string subed_str = sub_form(iformula,i);
					iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)/num_back(iformula,i)));
					i=0;
				}else{
					iformula = "#0#";
					i=0;
				}
			}break;

			case '%':{
				if(num_back(iformula,i)){
					string subed_str = sub_form(iformula,i);
					iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)%num_back(iformula,i)));
					i=0;
				}else{
					iformula = "#0#";
					i=0;
				}
			}break;
		}
	}
	for(int i=0; i<iformula.length(); i++){
		switch(iformula[i]){
			case '+':{
				string subed_str = sub_form(iformula,i);
				iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)+num_back(iformula,i)));
				i=0;
			}break;

			case '$':{
				string subed_str = sub_form(iformula,i);
				iformula = iformula.replace(iformula.find(subed_str), subed_str.length(), to_string(num_front(iformula,i)-num_back(iformula,i)));
				i=0;
			}break;
		}
	}
	return iformula;
}

int main(){
	string strResult;
	string formula;
	while(getline(cin, strResult)){
		formula = "#";
		for(int i=0; i<strResult.length(); i++){
			if(strResult[i] != ' '){
				if(strResult[i]=='-'){
					formula += '$';
				}else{
					formula += strResult[i];
				}
			}
		}
		formula += "#";
		cout << ans(math_logic(formula)) << endl;
	}
	
	return 0;
}