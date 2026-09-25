#include<iostream>
#include<sstream>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    while (cin >> n) {
        cin.ignore();
        for (int i = 0; i < n; i++) {
            // read intire line of Line i:
            stringstream ss;
            string line = "";
		    ss.str("");
            ss.clear();
            getline(cin, line);
            ss << line;
            long long a[100];
            long long* start_int = a;
            int length = 0;

            // read the numbers from Line i:
            // there will be length numbers in this line,
            // and they are stored in a[0], a[1], ..., a[length-1]
            while (ss) {
                ss >> *(start_int+length++);
                if (ss.eof()) {
                    break;
                }
            }

            // compare each pair of numbers in Line i:
            long long max = -1;
            for (int k = 0; k < length - 1; k++) {
                for (int j = k + 1; j < length; j++) {
                    // cout << start_int[k] << " " << start_int[j] << " " << gcd(start_int[k], start_int[j]) << endl;
                    if (gcd(start_int[k], start_int[j]) > max) {
                        max = gcd(start_int[k], start_int[j]);
                    }
                }
            }

            //output the maximum GCD found in Line i:
            cout << max << endl;

            // move to next line, and forget abouot current line, i would max in n-1.
        }
    }
}