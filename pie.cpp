#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main(){
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_int_distribution<int> dis(0,2147483647);
	long double in = 0.0f,count = 0.0f;
	long double x,y,pie;
	while(true){
		x=(long double)dis(gen)/(long double)2147483647.0f *(long double)2.0f - (long double)1.0f;
		y=(long double)dis(gen)/(long double)2147483647.0f * (long double)2.0f - (long double)1.0f;
		if(sqrt(x*x+y*y)<=1){
			in++;
		}
		count++;
		pie = ((long double)in/(long double)count) * (long double)4;
		//cout << "[" << count << "|" << x << "," << y <<"] " << pie << endl;
		cout << "[" << count << "] " << pie << endl;
	}
	return pie;
}
