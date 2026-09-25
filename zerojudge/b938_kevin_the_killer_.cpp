#include <iostream>
#include <cstdio>
#include <sstream>
#include <set>
#include <vector>
#pragma GCC optimize("Ofast") // O3加上一些快速但不安全的數學運算
using namespace std;

struct node
{

    node()
    {
        next = nullptr;
    }

    node(node *n)
    {
        next = n;
    }

    node(int num)
    {
        next = nullptr;
        code = num;
    }

    node(int num, node *n)
    {
        next = n;
        code = num;
    }

    node *next;
    int code;
};

struct linked_list
{

    vector<node> queue;
    int length;
    int max_length;
    vector<bool> is_killed;

    linked_list()
    {
        queue[0] = new node();
        length = 1;
    }

    linked_list(int len)
    {
        queue = vector<node>(len);
        is_killed = vector<bool>(len + 1, false);

        for (int i = 0; i < len - 1; i++)
        {
            queue[i].next = &queue[i + 1];
            queue[i].code = i + 1;
        }
        queue[len - 1].code = len;

        length = len;
        max_length = len;
    }

    int pop_next_node(int code)
    {
        if (length == 0)
            return -1;

        if (code < 1 || code >= max_length) // the code out of range, or is the last one
            return -1;

        // if (!killed.empty())
        //     if (killed.find(code) != killed.end()) return -1; // if corresponding code have been killed
        if (is_killed.size() != 0)
            if (is_killed[code]) return -1;

        node *object = &queue[code - 1];
        node *target = object->next;

        if (target == nullptr) // if the code is at the end of the list
            return -1;

        int result = target->code;

        // killed.insert(result);
        is_killed[result] = true;
        target->code = -1;
        object->next = target->next;
        length--;

        return result;
    }
};

int main()
{
    /*
        namings:

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
        linked_list queue(total);


        get_index_ss.clear();
        getline(cin, get_index_s);
        get_index_ss << get_index_s;

        while (get_index_ss >> index)
        {
            int result = queue.pop_next_node(index);
            if (result != -1) // if the corresponding index exists
                printf("%d\n", result);
            else
            { // if the corresponding index does not exist
                printf("0u0 ...... ?\n");
            }
        }
    }

    return 0;
}