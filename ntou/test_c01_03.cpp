#include<iostream>
#include<cmath>
using namespace std;

int main(){
	float rain[10] = {0,100,320,450,370,250,160,90,40,0};
	float P[5] = {0.5, 1.0, 1.5, 0.0, 0.5};
	for(int h=0; h<5; h++){
		float Q = 0;
		for(int i=0; i<5; i++){
			Q += rain[i+h] * P[4-i];
		}
		cout << "Q_" << h+1 << "=" << Q << endl;
	}
}