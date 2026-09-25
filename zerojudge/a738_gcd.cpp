#include <iostream>
using namespace std;

/*this question seems to be same to a024, see the solution using while loop*/

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        cout << gcd(a, b) << endl;
    }
}