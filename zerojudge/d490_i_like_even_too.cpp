#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a += 1;
    a >>=1;
    b >>=1;

    cout << ((a+b) * (b-a+1)) << endl;
}