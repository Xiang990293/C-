#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateParenthesesHelper(int n, string current, int open, int close) {
    if (close == n) {
        cout << current << endl;
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
    generateParenthesesHelper(n, "", 0, 0);
}

int main() {
    int n;
	cin >> n;
	while(n<=13){
		generateParentheses(n);
		cin >> n;
	}
    
    return 0;
}

