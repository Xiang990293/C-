#include <iostream>
#include <vector>
using namespace std;

void generateParentheses(int n) {
    string s(n * 2, ' ');
    for (int i = 0; i < n; ++i) {
        s[i] = '(';
        s[n + i] = ')';
    }
    cout << s << endl;
    while (true) {
        int i = n * 2 - 2;
        while (i >= 0 && s[i] != '(') --i;
        if (i < 0) break;
        int j = i + 1, cnt = 1;
        while (j < n * 2 && cnt > 0) {
            if (s[j] == '(') ++cnt;
            else if (s[j] == ')') --cnt;
            ++j;
        }
        if (j >= n * 2) break;
        s[i] = ')';
        s[j - 1] = '(';
        for (int k = i + 1, l = 0; k < n * 2; ++k) {
            if (k < j - 1) s[k] = '(';
            else if (k >= j) s[k] = ')';
            else s[k] = s[i + 1 + l++];
        }
        cout << s << endl;
    }
}


int main() {
    int n;
    while(cin>>n){
    	generateParentheses(n);
	}
    return 0;
}
