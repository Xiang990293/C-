#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct MathVector
{
    long long x, y;

    MathVector(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    MathVector operator+(MathVector other)
    {
        return MathVector(this->x + other.x, this->y + other.y);
    }

    MathVector operator-(MathVector other)
    {
        return MathVector(this->x - other.x, this->y - other.y);
    }

    bool operator==(MathVector other)
    {
        return this->x == other.x && this->y == other.y;
    }

    bool operator!=(MathVector other)
    {
        return this->x != other.x || this->y != other.y;
    }

    long long operator*(MathVector other)
    {
        return this->x * other.x + this->y * other.y;
    }

    void unitize()
    {
        this->x /= sqrt(this->x * this->x + this->y * this->y);
        this->y /= sqrt(this->x * this->x + this->y * this->y);
    }

    MathVector operator-=(MathVector other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    MathVector operator+=(MathVector other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
};

int main()
{
    int n, m, x, y;
    vector<vector<bool>> paper(500, vector<bool>(500, false));
    MathVector current_pos(0, 0);
    MathVector previous_pos(0, 0);
    MathVector delta(0, 0);
    while (cin >> n >> m)
    {
        paper = vector<vector<bool>>(500, vector<bool>(500, false));

        current_pos = MathVector(0, 0);
        previous_pos = MathVector(0, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            current_pos = MathVector(x, y);
            if (previous_pos == MathVector(0, 0))
            {
                previous_pos = current_pos;
                paper[previous_pos.x - 1][previous_pos.y - 1] = true;
                continue;
            }

            delta = current_pos - previous_pos;
            delta.unitize();
            while (previous_pos != current_pos)
            {
                previous_pos += delta;
                paper[previous_pos.x - 1][previous_pos.y - 1] = true;
            }
            previous_pos = current_pos;
        }

        for (int i = 0; i < n + 2; i++)
        {
            cout << "-";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "|";
            for (int j = 0; j < n; j++)
            {
                if (paper[i][j])
                    cout << "*";
                else
                    cout << " ";
            }
            cout << "|" << endl;
        }
        for (int i = 0; i < n + 2; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
}