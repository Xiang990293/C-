#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

const long double pi = 3.141592653589793238L;

long double deg_to_rad(long double deg){
	return deg*pi/180.0L;
}

long double rad_to_deg(long double rad){
	return rad/pi*180.0L;
}

class complex_number {
	public:
		long double real;
		long double imaginary;
		long double len;
		long double ang;
		
		void plus(complex_number a){
			this->real += a.real;
			this->imaginary += a.imaginary;
			fix(false);
		}
		
		void minus(complex_number a){
			this->real -= a.real;
			this->imaginary -= a.imaginary;
			fix(false);
		}
		
		void multiply(complex_number a){
			long double real = this->real;
			long double imaginary = this->imaginary;
			this->real = real*a.real - imaginary*a.imaginary;
			this->imaginary = real*a.imaginary + imaginary*a.real;
			fix(false);
		}
		
		void multiply(long double a){
			this->real *= a;
			this->imaginary *= a;
			fix(false);
		}
		
		void divid(complex_number a){
			long double n = a.real*a.real+a.imaginary*a.imaginary;
			long double real = this->real;
			long double imaginary = this->imaginary;
			this->real = (real*a.real + imaginary*a.imaginary)/n;
			this->imaginary = (imaginary*a.real - real*a.imaginary)/n;
			fix(false);
		}

		void power(long long a){
			complex_number b(1);
			complex_number c;
			c = *this;
			for(long long i=0; i<a; i++) b *= c;
			this->real=b.real;
			this->imaginary=b.imaginary;
			fix(false);
		}

		void turn(long double theta){
			long double thetad = rad_to_deg(theta);
			int a = thetad/360.0L;
			a >= 1? thetad = thetad-360*a : thetad = thetad;
			this->ang += deg_to_rad(thetad);
			fix(true);
		}
		
		complex_number& operator+=(complex_number a){
			this->plus(a);
			return *this;
		}

		complex_number& operator+(complex_number a){
			this->plus(a);
			return *this;
		}

		complex_number& operator-=(complex_number a){
			this->minus(a);
			return *this;
		}

		complex_number& operator-(complex_number a){
			this->minus(a);
			return *this;
		}
		
		complex_number& operator*=(complex_number a){
			this->multiply(a);
			return *this;
		}

		complex_number& operator*(complex_number a){
			this->multiply(a);
			return *this;
		}
		
		complex_number& operator/=(complex_number a){
			this->divid(a);
			return *this;
		}

		complex_number& operator/(complex_number a){
			this->divid(a);
			return *this;
		}

		complex_number& operator^=(long long a){
			this->power(a);
            return *this;
		}

		complex_number& operator^(long long a){
			this->power(a);
            return *this;
		}

		complex_number& operator=(complex_number a){
			this->real = a.real;
			this->imaginary = a.imaginary;
			return *this;
		}
		
		complex_number& operator=(long double a){
			this->real = a;
			this->imaginary = 0;
			return *this;
		}

		bool operator==(complex_number a){
			return ((this->real==a.real)&&(this->imaginary==a.imaginary));
        }

		bool operator==(long double a){
			complex_number ac(a);
			return *this==ac;
        }
		
		long double length(){
			long double real = this->real;
			long double imaginary = this->imaginary;
			return sqrt(real*real+imaginary*imaginary);
		}
		
		void show(){
			long double n = this->imaginary;
			if(n<0) cout << this->real << this->imaginary << "i" << endl;
			else cout << this->real << "+" << this->imaginary << "i" << endl;
			
		}
		
		complex_number(long double a, long double b){
			real = a;
			imaginary = b;
			len = sqrt(a*a+b*b);
			ang = atan2(b,a);
		}

		complex_number(long double a){
			real = a;
			imaginary = 0;
			len = sqrt(a*a+0);
			ang = atan2(0,a);
		}
		
		complex_number(){
			real = 0;
			imaginary = 0;
			len = 0;
			ang = 0;
		}

	private:
		bool is_zero(long double a){
			return a==0;
        }

		bool is_zero(complex_number a){
			return a==0;
        }

		void fix(bool is_in_right_angle_coordinate){
			if(is_in_right_angle_coordinate){
				long double len=this->len;
				long double ang=this->ang;
				this->real = len*fxcos(ang);
				this->imaginary = len*fxsin(ang);
			}else{
				long double a=this->real;
				long double b=this->imaginary;
				this->len = sqrt(a*a+b*b);
				this->ang = atan2(b,a);
			}
			this->real=this->real==0?0:this->real;
			this->imaginary=this->imaginary==0?0:this->imaginary;
			this->len=this->len==0?0:this->len;
			this->ang=this->ang==0?0:this->ang;
		}

		long double fxcos(long double theta){
			long double a = cos(theta);
			complex_number b(0,1);
			if(rad_to_deg(theta)/90.0L==round(rad_to_deg(theta)/90.0L)){
				b ^= round(rad_to_deg(theta)/90.0L);
				a = b.real;
			}
			return a;
		}

		long double fxsin(long double theta){
			long double a = sin(theta);
			complex_number b(0,1);
			if(rad_to_deg(theta)/90.0L==round(rad_to_deg(theta)/90.0L)){
				a = b.imaginary;
			}
			return a;
		}
};

complex_number fourier_transform(){
	complex_number a(0,0);
	return a;
}

int main(){
	complex_number a(1.0, 0.0);
	// cout << (rad_to_deg(deg_to_rad(360))/90.0L)<<endl;
	// cout << round(rad_to_deg(deg_to_rad(360))/90.0L)<<endl;
	// cout << (rad_to_deg(deg_to_rad(360))/90.0L==round(rad_to_deg(deg_to_rad(360))/90.0L))<<endl;
	// complex_number b(0.0, 1.0);
	// cout << round(rad_to_deg(deg_to_rad(360))/90.0L)<<endl;
	// b ^= 4;
	// b.show();
	// b.turn(0);
	// b.show();
	// b = complex_number(0.0, 1.0);
	// b ^= round(rad_to_deg(deg_to_rad(360))/90.0L);
	// b.show();
	// b.turn(0);
	// b.show();

	for(int j=0; j<8; j++){
		a.turn(deg_to_rad(45));
	}
	a.show();
	cout << a.imaginary << endl;
	cout << endl;
}
