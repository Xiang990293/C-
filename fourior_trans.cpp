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

long double angle_simplify(long double rad){
	if((rad_to_deg(rad)< -1*180.0L) || (rad_to_deg(rad) >=180.0L)){
		long double deg = rad_to_deg(rad);
		int semicircle = (floor(deg/180.0L));
		return deg_to_rad((abs(semicircle) % 2 == 1)? (deg - 180.0L*(semicircle+1)) : (deg - 180.0L*semicircle));
	}else{
		return rad;
	}
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

		void power(long double a){
			this->len = pow((this->len),a);
			this->ang = this->ang*a;
		}

		void turn(long double theta){
			this->ang = angle_simplify(deg_to_rad(rad_to_deg(this->ang) + rad_to_deg(angle_simplify(theta))));
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

		complex_number& operator%(long double a){
			this->turn(a);
			return *this;
		}

		complex_number& operator%=(long double a){
			this->turn(a);
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
			ang = (a==0)?(abs(b)!=b)?270:90:atan(b/a);;
		}

		complex_number(long double a){
			real = a;
			imaginary = 0;
			len = sqrt(a*a+0);
			ang = (abs(a)!=a)?180:0;
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
				this->ang = (a==0)?(abs(b)!=b)?270:90:atan(b/a);
			}
			this->real=this->real==0?0:this->real;
			this->imaginary=this->imaginary==0?0:this->imaginary;
			this->len=this->len==0?0:this->len;
			this->ang=this->ang==0?0:this->ang;
		}

		long double fxcos(long double theta){
			long double a = cos(theta);
			if(rad_to_deg(theta)/90.0L==round(rad_to_deg(theta)/90.0L)){
				complex_number one(0,1);
				complex_number b(0,1);
				long double added_theta = rad_to_deg(theta)+180.0L;
				switch(((int)round(added_theta/90.0L)+2)%4){
					case(0): one *= b;
					case(3): one *= b;
					case(2): one *= b;
				}
				a = one.real;
			}
			return a;
		}

		long double fxsin(long double theta){
			long double a = sin(theta);
			if(rad_to_deg(theta)/90.0L==round(rad_to_deg(theta)/90.0L)){
				complex_number one(0,1);
				complex_number b(0,1);
				long double added_theta = rad_to_deg(theta)+180.0L;
				switch(((int)round(added_theta/90.0L)+2)%4){
					case(0): one *= b;
					case(3): one *= b;
					case(2): one *= b;
				}
				a = one.imaginary;
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
	complex_number b(0.0, 1.0);
	
	for(int i=-1800; i<1800; i++){
		cout << i << ", ";
		a.turn(deg_to_rad(1));
		a.show();
	}
	a.show();
		
	
}