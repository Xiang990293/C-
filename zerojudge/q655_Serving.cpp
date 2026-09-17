#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

long long inverted_pair = 0;

void helper(vector<int> &a, int left, int right, vector<int> &temp) {
    // a: the array of data we want to find the inverted pair.
    // left, right: the index, 0 to (n-1).
    
    if (left == right) {
        temp[left] = a[left];
        return;
    }

    int mid = (left + right) / 2;
    
    helper(a, left, mid, temp);
    helper(a, mid + 1, right, temp);

    int pl = left;
    int pr = mid + 1;
    int pt = left;
    while (pl <= mid && pr <= right) {
        if (temp[pl] <= temp[pr]) {
            a[pt++] = temp[pl++];
        } else {
            a[pt++] = temp[pr++];
            inverted_pair += (long long)mid - (long long)pl + 1;
        }
    }

    while (pl <= mid) a[pt++] = temp[pl++];
    while (pr <= right) a[pt++] = temp[pr++];

    for (int i = left; i <= right; i++) {
        temp[i] = a[i];
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<queue<int>> dish(n);
    vector<int> eigen(n, 0);
    vector<int> temp(n, 0);

    int c,d;
    for (int i = 0; i < n; i++) {
        cin >> c >> d;

        dish[d-1].push(i);
        eigen[i] = c-1;
    }

    int k;
    for (int &j : eigen) {
        k = dish[j].front();
        dish[j].pop();
        j = k;
    }
    
    helper(eigen, 0, n-1, temp);
    cout << inverted_pair << endl;

    return 0;
}