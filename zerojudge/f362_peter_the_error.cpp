#include<iostream>
#include<vector>
#include<math.h>
#include<set>
#include<algorithm>
#include<iomanip>
#include<sstream>
using namespace std;

string round_to_2(long double a) {
    stringstream s;
    s.clear();
    s << fixed << setprecision(2) << a;
    return s.str();
}

int main() {
    long double n = 0;
    vector<long double> result;
    vector<string> sorting;
    vector<bool> validator;
    set<string> answered;
    string temp;
    while (cin >> n) {
        if (1-4*n < 0) {
            result = {
                abs((-1 - sqrt(1+4*n))/(long double)2),
                abs((-1 + sqrt(1+4*n))/(long double)2)
            };
            validator = {0, 0};
        } else {
            result = {
                abs((-1 - sqrt(1+4*n))/(long double)2),
                abs((-1 + sqrt(1+4*n))/(long double)2),
                abs((1 - sqrt(1-4*n))/(long double)2),
                abs((1 + sqrt(1-4*n))/(long double)2)
            };
            validator = {0, 0, 0, 0};
        }

        for (int i = 0; i < result.size(); i++) {
            if (abs(abs((result[i] - n)/(long double)result[i]) - result[i]) > 1e-17) continue;
            if (i < 2 && result[i] < n) validator[i] = 1;
            else if (i >= 2 && result[i] > n) validator[i] = 1;

            temp = round_to_2(result[i]);
            if (validator[i] && answered.find(temp) == answered.end()) {
                sorting.push_back(temp);
                answered.insert(temp);
            }
        }

        if (sorting.size() > 0) {
            sort(sorting.begin(), sorting.end());
            for (string &i : sorting) cout << i << " ";
        } else {
            cout << "NULL";
        }
        cout << endl;
        sorting = vector<string>(0);
        answered.clear();
    } 
}