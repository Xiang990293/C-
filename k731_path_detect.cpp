#include<iostream>
#include<vector>
#include<math.h>
#include<complex>
using namespace std;

int main(){
	int n=0, x_temp, y_temp;
	int left = 0, right = 0, back = 0;
	complex<double> dir(1,0);
	complex<double> p_now(0,0);
	complex<double> p_temp(0,0);
	complex<double> turning(0,0);
	while(cin>>n){
		cin >> x_temp >> y_temp;
		p_now = complex<double>(x_temp,y_temp);
		for(double i=1; i<n; i++){
			cin >> x_temp >> y_temp;
			p_temp = complex<double>(x_temp,y_temp);
			turning = ((p_temp-p_now)/dir);
			turning = turning/abs(turning);
			dir *= turning;
			if(turning == complex<double>(-1,0)) back++;
			else if(turning == complex<double>(0,1)) right++;
			else if(turning == complex<double>(0,-1)) left++;
			p_now = p_temp;
		}

		cout << right << " " << left << " " << back << endl;
	}
}