#include<iostream>
#include<unordered_map>
using namespace std;

istream& operator>>(istream& is, pair<int, int> &p) {
    char colon;

    if (is >> p.first >> colon >> p.second) {
        if (colon != ':') {
            is.setstate(ios::failbit);
        }
    }

    return is;
}

ostream& operator<<(ostream& os, pair<int, int> p) {
    os << p.first << ":" << p.second;

    return os;
}


int main() {
    unordered_map<int, int> a;
    pair<int, int> p;
    int sum = 0;
    bool is_state_input = true;

    while (cin >> p) {
        // cout << p << " " << pair<int, int>{0, 0} << endl;
        if (p == pair<int, int>{0, 0}) {
            if (is_state_input) is_state_input = false;
            else break;
        }

        if (is_state_input) {
            a.insert(p);
            continue;
        }

        if (a.find(p.first) != a.end()) {
            sum += a[p.first] * p.second;
        }
    }

    cout << sum << endl;

    return 0;
}