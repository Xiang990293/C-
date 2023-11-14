#include<string>
#include<sstream>
#include<iostream>
#include<regex>
using namespace std;

int regex_count(string text, regex expression){
	return distance(
		sregex_iterator(text.begin(), text.end(), expression),
		sregex_iterator());
}

int main(){
	string str, temp, num;
	string replacement;
	int sum, counter;
	regex digits("(^| )(\\d+)(?=$| )"), no("[\\D]");
	while(getline(cin, str)){
		sum = 0;
		smatch match1;
		counter = regex_count(str, digits);
		for(int i=0; i<counter; i++){
			regex_search(str, match1, digits);
			num = match1[2];
			try{
				sum += stoi(num);
				str = regex_replace(str, regex (digits), "", regex_constants::format_first_only);
			}catch(exception){
				str = regex_replace(str, regex (digits), "", regex_constants::format_first_only);
				continue;
			}
		}
	
		std::cout << sum << endl;
	}
}