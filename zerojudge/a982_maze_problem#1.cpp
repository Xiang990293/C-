#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>
#include<cstdio>
#include<iostream>
using namespace std;

struct queue {
    vector<pair<int, pair<int, int>>> array;
    int start = 0;
    int end = 0;
    int tsize = 0; // total size
    int usize = 0; // used size

    queue (int s) {
        tsize = s;
        array = vector<pair<int, pair<int, int>>>(tsize);
    }

    pair<int, pair<int, int>> pop() {
        if (start == end) return {-1, {-1, -1}};
        usize--;

        return array[start++];
    };

    void push(pair<int, pair<int, int>> a) {
        if (end == tsize && start > 0) end = 0;
        
        if (end + 1 == start) {
            printf("error: queue out of space");
        }
        usize++;
        array[end++] = a;
    }

    int size() {
        return usize;
    }
};

int helper(vector<vector<bool>> &board, vector<vector<bool>> &walked, queue &q, int nsize) {
    int x = 1, y = 1;
    pair<int, pair<int, int>> temp;
    vector<pair<int, int>> four_dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int len = 1;

    q.push({len, {x, y}});

    while (q.size() > 0) {
        temp = q.pop();
        len = temp.first;
        x = temp.second.first;
        y = temp.second.second;
        for (pair<int, int> &d : four_dir) {
            if (board[x + d.first][y + d.second]) {
                if (!walked[x + d.first][y + d.second]) {
                    q.push({len + 1, {x + d.first, y + d.second}});
                    walked[x + d.first][y + d.second] = 1;
                }

                if (x + d.first == nsize - 2 && y + d.second == nsize - 2) {
                    return len + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    int n;
    
    cin >> n;
    string a;
    char t1, t2;
    vector<vector<bool>> path(n, vector<bool>(n, 0));
    vector<vector<bool>> walked(n, vector<bool>(n, 0));
    queue q(n*n);


    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < n; j++) {
            path[i][j] = (a[j] == '.');
        }
    }

    int res = helper(path, walked, q, n);
    if (res >= 0) printf("%d", res);
    else printf("No solution!");

    return 0;
}