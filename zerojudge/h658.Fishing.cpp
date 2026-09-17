#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, n;
    cin >> x >> y;

    pair<int, int> start = {x, y};
    pair<int, int> result;
    int min = 2147483647;
    int dist;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        x -= start.first;
        y -= start.second;

        dist = x*x+y*y;
        if (min > dist) {
            min = dist;
            result = {x+start.first, y+start.second};
        }
    }

    cout << result.first << " " << result.second << endl;
}