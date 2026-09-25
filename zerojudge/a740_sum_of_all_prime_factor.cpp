#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

tuple<int, int> factor_helper(int n, int m)
{
    int result = 0;

    if (n % m == 0)
    {
        while (n % m == 0)
        {
            n /= m;
            result += m;
        }
    }

    return tuple(n, result);
}

void tuple_helper(int &a, int &b, tuple<int, int> t)
{
    a = get<0>(t);
    b += get<1>(t);
}

int factor(int n)
{
    int result = 0;
    int remain = n;

    tuple_helper(remain, result, factor_helper(remain, 2));
    tuple_helper(remain, result, factor_helper(remain, 3));

    for (int i = 5; i * i <= n; i += 6)
    {
        tuple_helper(remain, result, factor_helper(remain, i));
        tuple_helper(remain, result, factor_helper(remain, i + 2));
    }

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    if (remain != 1)
    {
        return result + remain;
    }

    return result;
}
int main()
{
    int n;
    while (cin >> n)
    {
        cout << factor(n) << endl;
    }
}