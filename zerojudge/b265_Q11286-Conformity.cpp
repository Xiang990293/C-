#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int main() {
    int n, m, max = 1, ctr = 0;
    vector<int> temp(500, 0);
    map<vector<int>, int> cnt;
    
    while (cin >> n) {
        if (n == 0) return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> m;
                temp[m]++;
            }
            if (++cnt[temp] > max) {
                max = cnt[temp];
            }
            temp = vector<int>(500, 0);
        }

        for (auto &i : cnt) if (i.second == max) ctr += i.second;
        cout << ctr << endl;
        cnt.clear();
        ctr = 0;
        max = 1;
    }
}