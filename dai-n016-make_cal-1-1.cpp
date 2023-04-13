#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

string oper = "+-*/%";

int sign(int a){
	if(a==0) return 0;
	else return a/abs(a);
}

double cal(double a, double b){
	return a/b;
}

int cal(int mode, int a, int b){
	switch(mode){
		case 0:
			return a+b;
		case 1:
			return a-b;
		case 2:
			return a*b;
		case 4:
			return sign(b)*abs((int)(a-floor(cal(a,b))*b));
	}
	return 0;
}

int main(){
	char sym;
	while(cin>>sym){
		if(sym=='E') break;
		int a, b;
		cin >> a >> b;
		int type=oper.find(sym);
		if(type==3) cout << cal(a,b) << endl;
		else cout << cal(type, a, b) <<endl;
	}

	return 0;
}

// int main() {
// 	char oper;
// 	while(cin>>oper){
// 		int a,b;
// 		cin >> a >> b;
// 		switch(oper){
// 			case '+':
// 				cout<<a+b<<endl;
// 				break;
// 			case '-':
// 				cout<<a-b<<endl;
// 				break;
// 			case '*':
// 				cout<<a*b<<endl;
// 				break;
// 			case '/':
// 				cout<<(float)a/(float)b<<endl;
// 				break;
// 			case '%':
// 				cout<<sign(b)*abs((int)(a-floor(cal(a,b))*b))<<endl;
// 		}
// 	}
// }

// int main(){

// 	// cout << cal(6303, 6634) << endl;
// 	ofstream input;
// 	input.open("測資/n016/n016_00.in");
// 	ofstream output;
// 	output.open("測資/n016/n016_00.out");
// 	for(int i = 0; i < 50000; i++){
// 		int a=rand()%20001-10000;
// 		int b=rand()%20001-10000;
// 		int c=rand()%5;

// 		input<<oper[c]<<" "<<a<<" "<<b<<"\n";
// 		(c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";
// 	}
// 	input<<"EOF";
// 	input.close();
// 	output.close();

// 	return 0;
// } 
