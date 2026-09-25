#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

// vector<unsigned long long> dp_series(4473); // since D must be at most 10^15, so n(n+1)/2 < 10^15 => n < 44721360

static const auto Initialize = []
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


inline unsigned long long series(unsigned long long s, unsigned long long a)
{   
    return (a - s + 1) * (a + s) / 2;
}

int main()
{
    unsigned long long S, D, sum, n;
    while (cin >> S >> D)
    {
        // for (n = S - 1, sum = S - 1; sum < D; sum = series(S, ++n)) continue;
        cout << fixed << setprecision(0) << ceil((-1 + sqrt(1+4*(2*D+S*S-S))) / 2) << endl;
    }
    return 0;
}