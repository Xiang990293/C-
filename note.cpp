#include <iostream>
#include <string>
using namespace std;

int alpha[26]={0};
bool has_zero_or_one_odd_character(string str) {
    for (int i=0; i<str.length(); i++){
        if (!isalpha(str[i])) continue;  // ignore non-alphabetic characters
        str[i] = tolower(str[i]);             // ignore case
        alpha[str[i]-97]++;
    }

    return true;
}

int main() {
    string str;
    while(cin >> str){
        if(has_zero_or_one_odd_character(str)){
            cout << "Yes !" << endl;
        } else {
            cout << "No..." << endl;
        }
    }
}
