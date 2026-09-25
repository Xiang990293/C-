#include <iostream>
#include <math.h>
using namespace std;

int super(int x)
{
  int y=1,i;
  for (i=1;i<=x+1;i++)
  {
    y = y * i;
  }
  return y;
}

int main()
{
    int n=10,f,g;
    float a,b;
    long double rate,c[n-1];
    cout << "Hello! please enter the chance for once" << endl;
    cout << "e.g.10%, enter 10" << endl;
    a = b = rate = 0;
    while (cin >> a)
    {
    a = a / 100.0;
    b = 1 - a;
    for (g=0;g<=n;g++)
    {
      f = n - g;
      c[g] = pow(a,f)*pow(b,g)*super(n)/(super(f)*super(g));
      rate = rate + c[g];
    }
    rate = rate * 100;
    cout << "Ten consecutive draws chance is " << rate << "%" <<endl;
    a = b = rate = 0;
    }
    return 0;
}
