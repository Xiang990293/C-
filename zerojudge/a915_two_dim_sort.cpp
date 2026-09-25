#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n, x, y;
    while (cin >> n)
    {
        queue<vector<int>> q;
        map<int, queue<vector<int>>> radise;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            q.push({x, y});
        }

        while (!q.empty())
        {
            vector<int> pair = q.front();
            if (radise.find(pair[1]) != radise.end())
            {
                radise[pair[1]].push(pair);
            }
            else
            {
                radise.emplace(pair[1], queue<vector<int>>());
                radise[pair[1]].push(pair);
            }
            q.pop();
        }

        for (auto i : radise)
        {
            while (!i.second.empty())
            {
                q.push(i.second.front());
                i.second.pop();
            }
        }
        radise.clear();

        while (!q.empty())
        {
            vector<int> pair = q.front();
            if (radise.find(pair[0]) != radise.end())
            {
                radise[pair[0]].push(pair);
            }
            else
            {
                radise.emplace(pair[0], queue<vector<int>>());
                radise[pair[0]].push(pair);
            }
            q.pop();
        }

        for (auto i : radise)
        {
            while (!i.second.empty())
            {
                q.push(i.second.front());
                i.second.pop();
            }
        }

        while (!q.empty())
        {
            vector<int> v = q.front();
            cout << v[0] << " " << v[1] << endl;
            q.pop();
        }
        radise.clear();
    }
}