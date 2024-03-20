#include<iostream>
using namespace std;

int main(){
	int i = 0;
	int j = 20;
	int k = 1020;
	int *p = &i;
	int *q = &j;
	int *r = &k;
	cout << "i\tj\tk" << endl
	<< i << "\t" << j << "\t" << k << endl
	<<*p << "\t" <<*q << "\t" <<*r << endl
	<< p << "\t" << q << "\t" << r << endl
	<<&p << "\t" <<&q << "\t" <<&r;
}