#include <iostream>
#include <math.h>
using namespace std;

int s1(int x)
{
	int y=1,i;
 	for (i=1;i<=x+1;i++) y *= i;
	return y;
}

int s2(int x)
{
  if(x==1) return 1;
  else return s2(x-1)*x;
}

int main()
{
    int n=10,f;
    float a,b;
    long double rate,c[n-1]={};
    a = b = rate = 0;
	while(cin >> a){
		a /= 100;
		b = 1 - a;
		for (int g=0;g<=n;g++){
			f = n - g;
			c[g] = pow(a,f)*pow(b,g)*s1(n)/(s1(f)*s1(g));
			rate += c[g];
		}
		rate *= 100;
		cout << rate << endl;
		a = b = rate = 0;
	}
	
    return 0;
}
