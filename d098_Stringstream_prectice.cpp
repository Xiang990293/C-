#include<string>
#include<sstream>
#include<iostream>
#include<regex>
using namespace std;

int main(){
	string str, copy, temp, num;
	string replacement;
	int sum;
	string stop;
	while(getline(cin, str)){
		sum = 0;
		stop = "";
		copy = str;
		smatch match1;
		while(regex_search(str, match1, regex ("(^| )\\b(\\d+)\\b($| )"))) {
			cout << stop << " " << str << endl;
			if(stop == str) break;
			stop = str;
			num = match1[2].str();
			temp = match1[0].str();
			if(regex_match(num, regex ("[^0-9]"))){
				str = regex_replace(str, regex ("\\b"+temp+"\\b"), " ", regex_constants::format_first_only);
			}
			try{
				sum += stoi(num);
				str = regex_replace(str, regex ("\\b"+temp+"\\b"), " ", regex_constants::format_first_only);
			}catch(exception){
				str = regex_replace(str, regex ("\\b"+temp+"\\b"), " ", regex_constants::format_first_only);
				continue;
			}
		}
	
		cout << sum << endl;
	}
}