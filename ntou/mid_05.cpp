#include<iostream>
#include<cmath>
using namespace std;

struct vec{
	int x;
	int y;
	int z;
	vec(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	}
	int dot(vec b){
		return x*b.x + y*b.y + z*b.z;
	}
	vec cross(vec b){
		return vec(y*b.z-z*b.y, z*b.x-x*b.z, y*b.z-z*b.y);
	}
	float len(){
		return sqrt(x*x+y*y+z*z);
	}
	void printv(){
		cout << "(" << x << "," << y << "," << z << "," << ")" << endl;
	}
};

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	vec vector1(a, b, c);
	cin >> a >> b >> c;
	vec vector2(a, b, c);

	int product = vector1.dot(vector2);
	cout << "內積為" << product << endl;
	float abs_atimesabs_b = abs(vector1.len()) * abs(vector2.len());
	cout << "夾角為" << (product / abs_atimesabs_b) << endl;
}

// int main(){
// 	int a, b, c;
// 	cin >> a >> b >> c;
// 	int d, e, f;
// 	cin >> d >> e >> f;

// 	int product = a*d+b*e+c*f;
// 	cout << "內積為" << product << endl;
// 	float abs_atimesabs_b = sqrt(a*a+b*b+c*c) * sqrt(d*d+e*e+f*f);
// 	cout << "夾角為" << (product / abs_atimesabs_b) << endl;
// }