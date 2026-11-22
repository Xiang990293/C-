#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    while (cin >> k) {
        k = abs(k);

        int n = 1;
        for (; (n * (n + 1) / 2 - k) % 2 != 0 || (n * (n + 1) / 2 - k) < 0; n++) {}

        cout << n << endl;
    }
    return 0;
}