#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

istream &operator>>(istream &is, vector<pair<char, vector<int>>> &v) {
    char alpha;
    int index, height;
    if (is >> alpha >> index >> height) {
        v.push_back({alpha, {index, height}});
    } else {
        is.setstate(ios::failbit);
    }

    return is;
}

int main() {
    int m;
    cin >> m;

    int n;
    cin >> n;

    vector<pair<char, vector<int>>> a;

    for (int i = 0; i < 6; i++) {
        cin >> a;
    }

    if (m % 2 == 1) {
        sort(a.begin(), a.end(), [](pair<char, vector<int>> &a, pair<char, vector<int>> &b) {
            return a.second[0] < b.second[0];
        });
    } else {
        sort(a.begin(), a.end(), [](pair<char, vector<int>> &a, pair<char, vector<int>> &b) {
            if (a.second[1] == b.second[1]) {
                return a.second[0] < b.second[0];
            }
            return a.second[1] < b.second[1];
        });
    }

    int order = 2 - n;
    if (order < 1) order += 6;

    cout << a[order].first << endl;

}