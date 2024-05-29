#include<iostream>
#include<sstream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int main(){
	stringstream s;
	string line, temp, result;
	long long tempi, recent;
	bool first;
	while(getline(cin, line)){
		if(line == "0, 0") break;
		s.str("");
		s.clear();
		s << line;
		result = "";
		first = true;
		vector<queue<int>> subs;
		vector<int> recents;
		vector<int> size;
		vector<bool> firsts;

		while(s >> temp){
			if(s.fail()) break;

			if(temp.substr(temp.length()-1, temp.length()) == ",") temp = temp.substr(0, temp.length()-1);
			tempi = stoll(temp);
			for(int i=0; i<subs.size(); i++){
				;
			}

			if(tempi >= recent || first){
				result += to_string(tempi) + ", ";
				recent = tempi;
				first = false;
			}
		}

		result = result.substr(0, result.length()-2);

		// printf("%s\n", result);
		cout << result << endl;
	}
}