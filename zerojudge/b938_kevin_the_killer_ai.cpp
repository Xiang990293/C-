#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#pragma GCC optimize("Ofast") // O3加上一些快速但不安全的數學運算
using namespace std;

static const auto Initialize = []
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main()
{
    /*
        nouns:

        node: each element of the linked list, as well as each person.
        linked_list: the entire queue of people.
        total: total number of people.
        count: number of person being killed.
        index: the index of the person. (1<= index <= total)
        code: the number on each person/node. (1<= index <= total), same as index at the beginning.
    */
    int total, count, index;
    stringstream get_index_ss;
    string get_index_s;

    while (cin >> total >> count)
    {
        cin.ignore();
        vector<int> next_index(total + 1);
        vector<bool> is_killed(total + 1, false);

        get_index_ss.clear();
        getline(cin, get_index_s);
        get_index_ss << get_index_s;

        for (int i = 1; i <= total; ++i)
            next_index[i] = i + 1;

        while (get_index_ss >> index)
        {

            if (index < 1 || index >= total || is_killed[index])
            {
                printf("0u0 ...... ?\n");
                continue;
            }

            int target = next_index[index];
            if (target == 0) // if the corresponding index exists
            {
                printf("0u0 ...... ?\n");
                continue;
            }

            is_killed[target] = true;
            next_index[index] = next_index[target];
            printf("%d\n", target);
        }

    }
    return 0;
}