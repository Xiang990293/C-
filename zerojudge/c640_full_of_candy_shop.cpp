#include <iostream>
#include <vector>
using namespace std;

istream &operator>>(istream &is, vector<int> &v) {
    if (is.peek() != '\n') return is;
    int i;
    is >> i;
    v.push_back(i);
    while (is.peek() == ' ') {
        is >> i;
        v.push_back(i);
    }

    return is;
}

int main() {
    long long m, k;
    long long n = 1;
    long long mprod = 1;
    vector<int> p;

    while (cin >> m >> k) {
        p.clear();
        mprod = 1;
        n = 1;
        cin >> p;

        
        for (auto &i : p) {
            mprod *= i;
        }

        while (mprod * n + k <= m) {
            cout << mprod * n++ + k << " ";
        }

        cout << endl;
    }
}