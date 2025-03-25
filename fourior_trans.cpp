#include<iostream>
#include<math.h>
#include<cmath>
#include<complex>
using namespace std;

const long double pi = 3.141592653589793238L;

long double deg_to_rad(long double deg){
	return deg*pi/180.0L;
}

long double rad_to_deg(long double rad){
	return rad/pi*180.0L;
}

long double angle_simplify(long double rad){
	if((rad_to_deg(rad)< -1*180.0L) || (rad_to_deg(rad) >=180.0L)){
		long double deg = rad_to_deg(rad);
		int semicircle = (floor(deg/180.0L));
		return deg_to_rad((abs(semicircle) % 2 == 1)? (deg - 180.0L*(semicircle+1)) : (deg - 180.0L*semicircle));
	}else{
		return rad;
	}
}

// complex fourier_transform(){
// 	complex a(0,0);
// 	return a;
// }

int main(){
	complex<long double> test(3,4);
	cout << sin(test) << " " << cos(test) << endl;
	// complex a(1.0, 0.0);
	// complex b(0.0, 1.0);

	return 0;
	
	// cout << "角度\t真值\t誤差對數\t誤差對數率\t誤差對數百分率\t數值" << endl;
	// for(int i=-1800; i<1800; i++){
	// 	cout << rad_to_deg(a.ang);
	// 	cout << "\t\t" << round(rad_to_deg(a.ang));
	// 	cout << "\t\t" << log2(abs(rad_to_deg(a.ang)-round(rad_to_deg(a.ang))));
	// 	cout << "\t" << log2(abs(rad_to_deg(a.ang)-round(rad_to_deg(a.ang)))/abs(round(rad_to_deg(a.ang))));
	// 	cout << "\t" << log2(abs(rad_to_deg(a.ang)-round(rad_to_deg(a.ang)))/abs(round(rad_to_deg(a.ang))))*100 << "%";
	// 	cout << "\t" << a.tostring() << endl;
	// 	a.turn(deg_to_rad(359));
	// }

	// cout << rad_to_deg(a.ang);
	// cout << "\t\t" << round(rad_to_deg(a.ang));
	// cout << "\t\t" << log2(abs(rad_to_deg(a.ang)-round(rad_to_deg(a.ang))));
	// cout << "\t" << log2(abs(rad_to_deg(a.ang)-round(rad_to_deg(a.ang))))/log2(abs(round(rad_to_deg(a.ang))));
	// cout << "\t" << log2(abs(rad_to_deg(a.ang)-round(rad_to_deg(a.ang)))/abs(round(rad_to_deg(a.ang))))*100 << "%";
	// cout << "\t" << a.tostring() << endl;
	// a.show();
	
}