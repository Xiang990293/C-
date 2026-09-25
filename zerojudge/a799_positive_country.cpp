#include<iostream>
using namespace std;

#define long long ll
#define unsigned long long ull

static const auto Initialize = [] {
    cin.sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();

int main() {
    int n;
    while(cin >> n) {
        cout << ((n & -2147483648)? -n : n) << endl;
    }
}