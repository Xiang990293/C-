#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

static const auto Initialize = []
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

vector<int> dp_fibonacci(47);

int fib(int n)
{
    dp_fibonacci[0] = 0; // F(0)
    dp_fibonacci[1] = 1; // F(1)
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n > 44)
        return fib(44);
    if (dp_fibonacci[n] != 0)
        return dp_fibonacci[n];

    dp_fibonacci[n] = fib(n - 1) + fib(n - 2);
    return dp_fibonacci[n];
}

int main()
{
    int n, m;
    int now_inx, now_fib;
    bool is_msd_printed = false;
    fib(44);
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            cout << m << " = ";
            is_msd_printed = false;

            now_inx = m <= 5 ? 5 + 1 : m;
            for (now_fib = fib(now_inx);now_fib > 0;now_fib = fib(now_inx--))
            {
                if (m >= now_fib)
                {
                    cout << "1";
                    m -= now_fib;
                    is_msd_printed = true;
                }
                else
                {
                    if (m < 1 && now_inx < 1)
                        break;
                    if (is_msd_printed)
                        cout << "0";
                }
            }
            cout << ((m >= 1) ? "1" : "") << " (fib)" << endl;
        }
    }
}