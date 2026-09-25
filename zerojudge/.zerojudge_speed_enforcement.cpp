#include<iostream>
#include <cstdio>
#include<sstream>
#pragma GCC optimize("Ofast")//O3加上一些快速但不安全的數學運算
using namespace std;


#define long long ll
#define unsigned long long ull

static const auto Initialize = [] {
    cin.sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();

//stringstream
stringstream get_string()
{
    string s;
    stringstream ss;
    ss.str("");
    ss.clear();
    getline(cin, s);
    ss << s;

    return ss;
}