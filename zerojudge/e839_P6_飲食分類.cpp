#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, vector<string>> food_cat;

    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        string F = "";
        string S = "";
        cin >> F >> S;
        food_cat[S].push_back(F);
    }

    string C = "";
    cin >> C;
    if (food_cat[C].empty()) cout << "No" << endl;
    else {
        sort(food_cat[C].begin(), food_cat[C].end(), [](string a, string b){
            return a < b;
        });
        for (string &i : food_cat[C]) {
            cout << i << endl;
        }
    }
}
