#include<iostream>
using namespace std;

int sum_of_positive_factor(int a) {
    if (a == 0) return 0;
    int sum = 0;
    int i;
    for (i = 1; i * i <= a; i++) {
        if (a % i == 0) sum += i + a / i;
    }
    if (--i * i == a) sum -= i;


    return sum;
}

int main() {
    int a;
    cin >> a;

    cout << sum_of_positive_factor(a)-a << endl;
}