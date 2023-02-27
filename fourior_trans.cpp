#include<iostream>
#include<math.h>
using namespace std;

const long long pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798;

long long deg_to_rad(long long deg){
	return deg*pi/180;
}

long long rad_to_deg(long long rad){
	return rad/pi*180;
} 

class complex_number {
public:
	long long real;
	long long imaginary;
	
	void plus(complex_number a){
		this->real += a.real;
		this->imaginary += a.imaginary;
	}
	
	void minus(complex_number a){
		this->real -= a.real;
		this->imaginary -= a.imaginary;
	}
	
	void multiply(complex_number a){
		long long real = this->real;
		long long imaginary = this->imaginary;
		this->real = real*a.real - imaginary*a.imaginary;
		this->imaginary = real*a.imaginary + imaginary*a.real;
	}
	
	void divid(complex_number a){
		long long n = a.real*a.real+a.imaginary*a.imaginary;
		long long real = this->real;
		long long imaginary = this->imaginary;
		this->real = (real*a.real + imaginary*a.imaginary)/n;
		this->imaginary = (imaginary*a.real - real*a.imaginary)/n;
	}
	
	void turn(long long theta){
		complex_number a(cos(deg_to_rad(theta)), sin(deg_to_rad(theta)));
		this->multiply(a);
	}
	
	long long abs(){
		long long real = this->real;
		long long imaginary = this->imaginary;
		return sqrt(real*real+imaginary*imaginary);
	}
	
	void show(){
		cout << this->real << "+" << this->imaginary << "i" << endl;
	}
	
	complex_number(long long a, long long b){
		real = a;
		imaginary = b;
	}
};

int fourier_transform(){
	
}

int main(){
	complex_number a(1.0, 0.0);
	
	a.show();
	cout << a.abs() << endl;
	cout << cos(deg_to_rad(45.0)) << " "<< sin(deg_to_rad(45.0)) << endl;
	complex_number b(cos(deg_to_rad(45.0)), sin(deg_to_rad(45.0)));
	b.show();
	a.turn(45.0);
	a.show();
	cout << a.abs() << endl;
	a.multiply(b);
	a.show();
	cout << a.abs() << endl;
}
