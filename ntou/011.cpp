#include<iostream>
using namespace std;

long long factorial(long long aim){
	if(aim == 0) return 1;
	if(aim == 1) return 1;
	return aim*factorial(aim-1);
}

float trans_temp(float cel){
	return cel*9/5+32;
}

int main(){
	float a;
	cout.precision(5);
	cout.setf(ios::fixed);
	while(cin >> a) cout << trans_temp(a) << endl;
}