#include<iostream>
using namespace std;

int main(){
	int a, b, c, d, x, y;
	cout.precision(2);
	cout << fixed;
	while(cin >> a >> b >> x >> c >> d >> y){
		bool special = 0;
		bool same_bias = 0;
		long double det = a*d-b*c;
		if(det == 0) special = 1;
		long double p = d*x-b*y;
		long double q = -c*x+a*y;
		same_bias = (p == q);
		if(!special) cout << "x=" << p / det << endl << "y=" << q / det << endl;
		else if(same_bias && p == 0) cout << "Too many" << endl;
		else cout << "No answer" << endl;
	}
}