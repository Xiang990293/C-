#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    string a;
    long double p, l, w, r;
    vector<pair<string ,long double>> result;
    for (int i = 0; i < n; i++) {
        cin >> a >> p >> l >> w >> r;
        result.push_back({a, p * w / l * r});
    }

    sort(result.begin(), result.end(), [](auto a, auto b){
        return a.second > b.second;
    });

    for (int i = 0; i < n; i++) {
        cout << result[i].first << endl;
    }
}