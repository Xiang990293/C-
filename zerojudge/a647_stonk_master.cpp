#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
    int n, m, p;
    long double result;
    while(cin>>n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> m >> p;
            result = (long double)(p-m)/m*100;
            result += result>=0 ? 0.0000001 : -0.0000001;

            cout << fixed << setprecision(2) << result << "% " << ((result<10 && result>-7)? "keep" : "dispose") << endl;
        }
    }
}