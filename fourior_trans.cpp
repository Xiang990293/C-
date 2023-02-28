#include<iostream>
#include<math.h>
using namespace std;

const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798;

long double deg_to_rad(long double deg){
	return deg*pi/180.0;
}

long double rad_to_deg(long double rad){
	return rad/pi*180.0;
}

class rad{
public:
	long double rad;

};

class complex_number {
	public:
		long double real;
		long double imaginary;
		long double len;
		long double ang;
		
		void plus(complex_number a){
			this->real += a.real;
			this->imaginary += a.imaginary;
		}
		
		void minus(complex_number a){
			this->real -= a.real;
			this->imaginary -= a.imaginary;
		}
		
		void multiply(complex_number a){
			long double real = this->real;
			long double imaginary = this->imaginary;
			this->real = real*a.real - imaginary*a.imaginary;
			this->imaginary = real*a.imaginary + imaginary*a.real;
		}
		
		void multiply(long double a){
			this->real *= a;
			this->imaginary *= a;
		}
		
		void divid(complex_number a){
			long double n = a.real*a.real+a.imaginary*a.imaginary;
			long double real = this->real;
			long double imaginary = this->imaginary;
			this->real = (real*a.real + imaginary*a.imaginary)/n;
			this->imaginary = (imaginary*a.real - real*a.imaginary)/n;
		}
		
		complex_number& operator+=(complex_number a){
			this->plus(a);
			return *this;
		}

		complex_number& operator-=(complex_number a){
			this->minus(a);
			return *this;
		}
		
		complex_number& operator*=(complex_number a){
			this->multiply(a);
			return *this;
		}
		
		complex_number& operator/=(complex_number a){
			this->divid(a);
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

		
		void turn(long double theta){
			complex_number a(cos(deg_to_rad(theta)), sin(deg_to_rad(theta)));
			this->multiply(a);
		}
		
		long double length(){
			long double real = this->real;
			long double imaginary = this->imaginary;
			return sqrt(real*real+imaginary*imaginary);
		}
		
		void show(){
			int n = this->imaginary;
			char p = {0};
			if(abs(n)==n) p='+';
			cout << this->real << p << this->imaginary << "i" << endl;
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

		void fix(long double a, long double b,bool is_in_vertical_coordinate){
			if(is_in_vertical_coordinate){
				this->real = a*cos(b);
				this->imaginary = a*sin(b);
			}else{
				this->len = sqrt(a*a+b*b);
				this->ang = atan2(b,a);
			}
		}
};

complex_number fourier_transform(){
	complex_number a(0,0);
	return a;
}

int main(){
	complex_number a(1.0, 0.0);
	complex_number b(cos(pi/4), sin(pi/4));
	
	a.show();
	b.show();
	cout << endl;
	
	for(int i=0; i<8; i++){
		a.multiply(b);
		a.show();
		cout << a.real << endl << endl;
	}
	
}
