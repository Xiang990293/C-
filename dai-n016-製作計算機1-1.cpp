#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

string oper[5] = {"+","-","*","/","%"};

int cal(int mode, int a, int b){
	switch(mode){
		case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        case 4:
            return a%b;
	}
}

float cal(int a, int b){
	return (float)a/(float)b;
}

int main(){
	ofstream input;
	input.open("測資/n016_00.in");
	ofstream output;
	output.open("測資/n016_00.out");
	for(int i = 0; i < 50000; i++){
		int a=rand()%20001-10000;
		int b=rand()%20001-10000;
		int c=rand()%5;

		input<<oper[c]<<" "<<a<<" "<<b<<"\n";
		(c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";
	}
	input.close();
	output.close();

	return 0;
} 
