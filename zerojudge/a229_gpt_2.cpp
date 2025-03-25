#include <iostream>
#include <vector>
#include <string>
using namespace std;

string output = "";
string all[13] = {};

void generateParenthesesHelper(int n, string current, int open, int close) {
	if (close == n) {
		output += current + "\n";
		return;
	}
	if (open < n) {
		generateParenthesesHelper(n, current + "(", open + 1, close);
	}
	if (close < open) {
		generateParenthesesHelper(n, current + ")", open, close + 1);
	}
}

void generateParentheses(int n) {
	output = "";
	if(all[n]!=""){
		output = all[n];
		return;
	}
	generateParenthesesHelper(n, "", 0, 0);
	all[n] = output;
}

int main() {
	int n;
	cin >> n;
	while(n<=13){
		generateParentheses(n);
		cout << output;
		cin >> n;
	}
	
	return 0;
}