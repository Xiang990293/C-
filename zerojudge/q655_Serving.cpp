#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> helper(vector<int> &a, int left, int right, int &inverted_pair) {
    // left, right: the number count by left, start from 1,
    // notice that we need to - 1 before indexing arraies.
    
    if (left == right) return vector<int>(1, a[left-1]);
    
    vector<int> vl = helper(a, left, (left + right) / 2, inverted_pair);
    vector<int> vr = helper(a, (left + right) / 2 + 1, right, inverted_pair);

    int pl = vl.size(), pr = vr.size();
    vector<int> vt(pl + pr, 0);
    int pt = vt.size();
    while (pl > 0 && pr > 0) {
        if (vl[pl - 1] > vr[pr - 1]) {
            vt[--pt] = vl[--pl];
            inverted_pair += pr;
        } else {
            vt[--pt] = vr[--pr];
        }
    }

    if (pl > 0) while (pl > 0) vt[--pt] = vl[--pl];
    if (pr > 0) while (pr > 0) vt[--pt] = vr[--pr];

    return vt;
}

int reverted_pair(vector<int> &a) {
    int result = 0;
    helper(a, 1, a.size(), result);

    return result;
}

int main() {
    int n;
    cin >> n;
    queue<int> dish[n+1];
    vector<int> eigen;
    
    int c,d;
    for (int i = 1; i <= n; i++) {
        cin >> c >> d;

        dish[d].push(i);
        eigen.push_back(c);
    }

    int k;
    for (int &j : eigen) {
        k = dish[j].front();
        dish[j].pop();
        j = k;
    }
    
    cout << reverted_pair(eigen) << endl;
}