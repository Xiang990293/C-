#include <iostream>
#include <string>
using namespace std;

bool has_zero_or_one_odd_character(string str) {
	int alpha[26]={0};
	int odd_counter=0;
    for (int i=0; i<str.length(); i++){
        if (!isalpha(str[i])) continue;
        str[i] = tolower(str[i]);
        alpha[str[i]-97]++;
    }
	for (int i=0; i<26; i++){
		if (alpha[i]%2==1) odd_counter++;
		if (odd_counter>=2) return false;
	}

    return true;
}

int main() {
    string str;
    while(cin >> str){
        if(has_zero_or_one_odd_character(str)){
            cout << "yes !" << endl;
        } else {
            cout << "no..." << endl;
        }
    }
}
