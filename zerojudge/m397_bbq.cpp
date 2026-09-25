#include<iostream>
using namespace std;

int main() {
    int n, m, x, y;
    while(cin >> n >> m >> x >> y) {
        int is_x_larger = x > y;
        int max = is_x_larger ? x : y;

        int c_y = max * m - n;
        if (c_y < 0) {
            cout << "-1 -1" << endl;
            continue;
        }

        int min = (x + y - max);
        c_y /= max - min;
        int c_x = m - c_y;

        if (c_x * max + c_y * min != n) {
            cout << "-1 -1" << endl;
            continue;
        }
        
        if (!is_x_larger) {
            int temp = c_x;
            c_x = c_y;
            c_y = temp;
        }

        if (c_x < 0 || c_y < 0) {
            cout << "-1 -1" << endl;
            continue;
        }

        cout << c_x << " " << c_y << endl;
    }
}