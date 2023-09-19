#include<iostream>
#include<vector>
#include<math.h>
#include<complex>
using namespace std;

vector<double> add(vector<double> v1, vector<double> v2) {
	int size = v1.size();
	double sum[size];

    for (int i = 0; i < size; i++) sum[i] = (v1[i] + v2[i]);

	vector<double> s(sum, sum+size);

    return s;
}

int main(){
	bool a = 0;
	a = ~a;
	cout << a << endl;

	return 0;
}