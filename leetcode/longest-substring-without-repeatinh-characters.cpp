#include<stack>
#include<cstring>
#include<iostream>
using namespace std;

class Solution {
public:
    string alpha = "";
    bool if_repeat(char a){
        for(int i=0; i<26; i++){
            if(alpha[i] == a){
                return true;
            }
        }

        return false;
    }

    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        stack<string> sub;
        string current = "";
        for(int i=0; i<len; i++) {
            if(if_repeat(s[i])) {
                sub.push(current);
                alpha = "";
                current = "";
            }
            current += s[i];
            alpha += s[i];
        }

        len = sub.size();
        int max = 0;
        int size = 0;
        for(int i = 0; i<len; i++){
            current = sub.top();
            size = current.length();
            if(size > max) max = size;
            sub.pop();
        }

        return max;
    }
};

int main(){
	Solution Xiang990293;
	string input1 = "abcabcbb";
	string input2 = "bbbbb";
	string input3 = "pwwkew";
	cout << Xiang990293.lengthOfLongestSubstring(input3) << endl;
}