#include<string>
#include<sstream>
#include<iostream>
#include<cctype>
#include<regex>
using namespace std;

int main(){
	string str, copy, temp;
	string replacement;
	double sum;
	int i=0;
	while(getline(cin, str)){
		i++;
		sum = 0;
		copy = str;
		// if(i==35) cout << str << endl;
		smatch match1;
		while(regex_search(str, match1, regex ("(^| )\\b[0-9]+\\b($| )"))) {
			cout << str << endl;
			temp = match1[0].str();
			if(regex_match(temp, regex ("[^0-9]"))){
			}
			try{
				sum += stod(temp);
				str = regex_replace(str, regex ("\\b"+temp+"\\b"), "", regex_constants::format_first_only);
			}catch(exception){
				str = regex_replace(str, regex ("\\b"+temp+"\\b"), "", regex_constants::format_first_only);
				continue;
			}
		}
		// cout << str << endl;

		// regex_replace(copy, regex ("\\b[0-9]+\\b"), "");

		// smatch match1;
		// while(regex_search(copy, match1, regex ("\\b[0-9]+\\b"))) {
		// 	cout << copy << endl;
		// 	temp = match1[0].str();
		// 	copy = regex_replace(copy, regex ("\\b"+temp+"\\b"), "");
		// }

		// cout << copy << endl;

		// smatch match2;
		// while(regex_search(copy, match2, regex ("\\b[^ ]+\\b"))) {
		// 	temp = match2[0].str();
		// 	str = regex_replace(str, regex (""+temp+""), "");
		// }

		// smatch match3;
		// while(regex_search(copy, match3, regex ("\\(?<= |^\\)\\b\\(.+?\\)\\b\\(?= |$\\)"))) {
		// 	temp = match3[0].str();
		// 	sum += stoi(temp);
		// 	str = regex_replace(str, regex (temp), "");
		// }
	
		cout << sum << endl;
	}
}
