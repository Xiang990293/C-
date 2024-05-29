#include <iostream>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <complex>
#include <regex>
#include <sstream>
#include <algorithm>
#include <graphics.h>
using namespace std;

int main()
{
	for(int i =0; i< 1000; i++) {
		if (~i * ~0 != i + 1) cout << "no" << endl;
		cout << ~i * ~0 << endl;
	}
}