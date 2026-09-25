#include<iostream>
#include<set>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (b > a) return gcd(b, a);

    return gcd(a % b, b);
}

int gcd3(int a, int b, int c) {
    return gcd(gcd(a, b), c);
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

int main() {
    int n;
    int a, b, c;
    int ctr = 0;

    set<vector<int>> result;
    int gcdd;
    vector<int> temp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        gcdd = gcd3(a, b, c);
        a /= gcdd;
        b /= gcdd;
        c /= gcdd;

        if (a > b) {
            if (c > a) {swap(a, c); swap(b, c);}
            else if (c < b) n += 0;
            else swap(b, c);
        } else {
            if (c > b) swap(a, c);
            else if (c < a) swap(a, b);
            else {swap(a, b); swap(b, c);}
        }

        temp = {a, b, c};

        if (result.find(temp) == result.end()) {
            ctr++;
            result.insert(temp);
        }
    }

    cout << ctr << endl;
}