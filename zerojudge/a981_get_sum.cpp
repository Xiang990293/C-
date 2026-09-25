#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>
using namespace std;

vector<tuple<string, int>> helper(vector<int>& remain_numbers,vector<int>::iterator remain_numbers_begin, vector<int>::iterator remain_numbers_end, int goal, int remain_sum)
{
    if (remain_numbers_begin == remain_numbers_end || goal <= 0)
    {
        return vector<tuple<string, int>>(1, tuple("", goal == 0 ? 0 : -1));
    }

    if (goal > remain_sum)
    {
        return vector<tuple<string, int>>(1, tuple("", -1));
    }

    vector<tuple<string, int>> final_result;
    int head = *remain_numbers_begin;

    auto result_1 = helper(remain_numbers, remain_numbers_begin + 1, remain_numbers_end, goal - head, remain_sum - head);
    for (auto& i : result_1)
    {
        if (get<1>(i) == -1)
            continue;
        string result = "";
        int sum = 0;
        result += get<0>(i) + " " + to_string(head);
        sum += head + get<1>(i);

        final_result.push_back(tuple(result, sum));
    }

    auto result_0 = helper(remain_numbers, remain_numbers_begin + 1, remain_numbers_end, goal, remain_sum - head);
    for (auto& i : result_0)
    {
        if (get<1>(i) == -1)
            continue;
        string result = "";
        int sum = 0;
        result += get<0>(i);
        sum += get<1>(i);

        final_result.push_back(tuple(result, sum));
    }

    return final_result;
}

int main()
{
    int n, g;
    while (cin >> n >> g)
    {
        vector<int> all(n);

        for (int i = 0; i < n; i++)
        {
            cin >> all[i];
        }

        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += all[i];
        }

        if (sum < g)
        {
            cout << "-1" << endl;
            continue;
        }

        auto result = helper(all, all.begin(), all.end(), g, sum);
        // reverse(result.begin(), result.end());

        bool have_sol = false;
        for (auto& i : result)
        {
            if (get<1>(i) == g)
            {
                stringstream ss;
                string temp = "";
                string result = "";
                ss.str("");
                ss.clear();
                ss << get<0>(i).substr(1);
                while (ss >> temp)
                    result = temp + " " + result;
                cout << result << endl;
                // cout << get<0>(i).substr(1) << endl;
                have_sol = true;
            }
        }

        if (!have_sol)
        {
            cout << "-1" << endl;
        }
    }
}
