#include<iostream>
using namespace std;

int main() {
    long long n, m, l, r;
    while (cin >> n) {
        cin >> m;
        int count = 0;
        for (int i = 0; i < m; i++) {
            cin >> l >> r;
            count += (r - l + 1);
        }
        
        // Calculate the number of 1s in the final sequence
        if (count % 2 == 0) {
            cout << n - count / 2 << endl;
        } else {
            cout << n - count / 2 - 1 << endl;
        }
    }
}


// #include<iostream>
// #include<vector>
// using namespace std;

// int main() {
//     long long n, m, l, r;
//     while (cin >> n) {
//         cin >> m;
//         vector<int> bits(n + 1, 0);  // Initialize all bits to 0
//         for (int i = 0; i < m; i++) {
//             cin >> l >> r;
//             for (int j = l; j <= r; j++) {
//                 // Toggle the bit (0 to 1 or 1 to 0)
//                 bits[j] = 1 - bits[j];
//             }
//         }

//         int count = 0;
//         for (int i = 1; i <= n; i++) {
//             if (bits[i] == 1) {
//                 count++;
//             }
//         }

//         cout << n - count << endl;
//     }
// }
