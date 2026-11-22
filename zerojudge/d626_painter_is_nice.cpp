#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cin >> n;

    char arr[n][n];
    vector<vector<bool>> stepped(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int r, c;
    cin >> r >> c;
    
    char target = ((arr[r][c]) == '+' ? '-' : '+');
    int qf = 0, qe = 0;
    vector<pair<int, int>> q;
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    q.push_back({r, c});
    qe++;

    while(qf != qe) {
        pair<int, int> p = q[qf++];
        arr[r][c] = target;
        r = p.first;
        c = p.second;
        stepped[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int i = dir[d].first;
            int j = dir[d].second;
            if (r + i < 0 || r + i >= n || c + j < 0 || c >= n) continue;
            if (stepped[r + i][c + j]) continue;
            if (arr[r + i][c + j] == target) continue;

            q.push_back({r + i, c + j});
            qe++;
            
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j];
        cout << endl;
    }
}