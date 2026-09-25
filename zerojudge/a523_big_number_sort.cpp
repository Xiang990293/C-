#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BigNum
{
    vector<int> num;
    int len;
    bool sign;
    BigNum(string s)
    {
        sign = (s[0] == '-');
        s = sign ? s.substr(1) : s;
        len = s.size();
        num.resize(len);
        for (int i = 0; i < len; i++)
            num[i] = s[i] - '0';
    }

    BigNum()
    {
        len = 1;
        sign = false;
        num.resize(1);
        num[0] = 0;
    }

    BigNum operator=(BigNum b)
    {
        len = b.len;
        sign = b.sign;
        num.resize(len);
        for (int i = 0; i < len; i++)
            num[i] = b.num[i];
        return *this;
    }

    bool operator<(BigNum b)
    {
        if (sign != b.sign)
            return sign > b.sign;
        if (len != b.len)
            return (len < b.len) ^ sign;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[i] != b.num[i])
                return (num[i] < b.num[i]) ^ sign;
        }
        return false;
    }

    bool operator>(BigNum b)
    {
        if (sign != b.sign)
            return sign < b.sign;
        if (len != b.len)
            return (len > b.len) ^ sign;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[i] != b.num[i])
                return (num[i] > b.num[i]) ^ sign;
        }
        return false;
    }

    bool operator==(BigNum b)
    {
        if (len != b.len)
            return false;
        if (sign != b.sign)
            return false;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[i] != b.num[i])
                return false;
        }
        return true;
    }

    bool operator!=(BigNum b)
    {
        return !(*this == b);
    }

    bool operator<=(BigNum b)
    {
        return !(*this > b);
    }

    bool operator>=(BigNum b)
    {
        return !(*this < b);
    }

    void print()
    {
        if (sign)
            cout << '-';
        for (int i = 0; i < len; i++)
            cout << num[i];
        cout << endl;
    }

    string to_string()
    {
        string s = "";
        if (sign)
            s += '-';
        for (int i = 0; i < len; i++)
            s += num[i] + '0';
        return s;
    }

    friend istream &operator>>(istream &in, BigNum &b)
    {
        string s;
        in >> s;
        b = BigNum(s);
        return in;
    }
};

int main()
{
    int n;
    while (cin >> n)
    {
        vector<BigNum> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            v[i].print();
    }
}