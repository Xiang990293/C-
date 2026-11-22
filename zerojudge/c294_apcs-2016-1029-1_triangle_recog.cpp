#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    double s = (double)(a + b + c)/(double)2;
    
    if (b < a) swap(a, b);
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    cout << a << " " << b << " " << c << endl;
    
    if (s * (s - a) * (s - b) * (s - c) <= 0) {
        cout << "No" << endl;
        return 0;
    } else if (c * c == b * b + a * a) {
        cout << "Right" << endl;
    } else if (c * c > b * b + a * a) {
        cout << "Obtuse" << endl;
    } else {
        cout << "Acute" << endl;
    }

    return 0;
}