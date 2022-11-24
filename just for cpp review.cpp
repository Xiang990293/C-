#include <iostream>
using namespace std;
int main()
{
	float k;
    while (cin >> k)
    {
    	int a1=1, a2=1, da=0;
    	cout << 1 << " | " << 1 << endl;
    	cout << 2 << " | " << 1 << endl;
        for (int i=0; i<k-2; i++){
        	da = a2;
        	a2 = a1 + a2;
        	a1 = da;
        	cout << i+3 << " | " << a2 << endl;
		}
		cout << a2 << endl;
		cout << "黃金比例：" << (float)a2/(float)a1 << endl;
    }
    return 0;
}

