#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

string oper = "+-*/%";

long sign(int a){
	if(a==0) return 0;
	else return a/abs(a);
}

long double cal(long double a, long double b){
	if(b==0) return 0;
	return a/b;
}

long long cal(long long mode, long long a, long long b){
	switch(mode){
		case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        case 4:
            if(b==0) return 0;
			else return sign(b)*abs((long long)(a-floor(cal(a,b))*b));
	}
	return 0;
}

int main(){
	ofstream input;
	input.open("測資/n017/n017_01.in");
	ofstream output;
	output.open("測資/n017/n017_01.out");
	for(int i = 0; i < 50000; i++){
		long double x = (long double) rand() / (RAND_MAX + 1.0);
		long long a=x*4000000001-2000000000;
		long double y = (long double) rand() / (RAND_MAX + 1.0);
		long long b=y*4000000001-2000000000;
		int c=rand()%5;

		input<<a<< " " <<oper[c]<< " " <<b<<"\n";
		(c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";
		// input<<a <<oper[c] <<b<<"\n";
		// (c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";
		// input<<a<< ((rand()%2==1)?" ":"") <<oper[c]<< ((rand()%2==1)?" ":"") <<b<<"\n";
		// (c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";
	}
	input<<"EOF";
	input.close();
	output.close();

	return 0;
} 
