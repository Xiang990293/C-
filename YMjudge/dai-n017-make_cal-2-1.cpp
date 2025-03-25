#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

string oper = "-+*/%";

int sign(long double a){
	if(a==0) return 0;
	else return (a>0)?1:-1;
}

string cal(long double a, long double b){
	if(b==0) return "nan";
	return to_string(a/b);
}

string cal(int mode, long long a, long long b){
	switch(mode){
		case 0:
            return to_string(a-b);
        case 1:
            return to_string(a+b);
        case 2:
			return to_string(a*b);
        case 4:
            if(b==0) return "nan";
			else return to_string(sign(b)*abs((long long)(a-floor((long double)a/(long double)b)*b)));
	}
	return 0;
}

int main(){
	// cout << -1940063476 << " " << -1634399413 << " " << (long long)(-1940063476) * (long long)(-1634399413) << " " << to_string((long long)((long long)-1940063476 * (long long)-1634399413)) << endl;
	string strResult;
	while(getline(cin, strResult)){
		if(strResult=="EOF") break;
		while(strResult.find(" ")!=-1){
			strResult = strResult.replace(strResult.find(" "),1,"");
		}
		while(strResult[0]=='-'){
			strResult = strResult.replace(0,1,"$");
		}
		int i;
		for(i=4; strResult.find(oper[i])==-1; i--){}

		int type=i;
		int pos=strResult.find(oper[i]);
		while(strResult[pos+1]=='-'){
			strResult = strResult.replace(pos+1,1,"$");
		}

		string at=strResult.substr(0,pos), bt=strResult.substr(pos+1,strResult.length());
		while(at[0]=='$'){
			at = at.replace(0,1,"-");
		}
		while(bt[0]=='$'){
			bt = bt.replace(0,1,"-");
		}

		long long a=stoll(at), b=stoll(bt);
		
		if(type==3) cout << cal(a,b) << endl;
		else cout << cal(type, a, b) <<endl;
	}
	return 0;
}

// int main(){
// 	ofstream input;
// 	input.open("測資/n017/n017_01.in");
// 	ofstream output;
// 	output.open("測資/n017/n017_01.out");
// 	srand (time(NULL));
// 	for(int i = 0; i < 50000; i++){
// 		long double x = (long double) rand() / (RAND_MAX + 1.0);
// 		long long a=x*4000000001-2000000000;
// 		long double y = (long double) rand() / (RAND_MAX + 1.0);
// 		long long b=y*4000000001-2000000000;
// 		int c=rand()%5;

// 		//both " "
// 		// input<<a<< " " <<oper[c]<< " " <<b<<"\n";
// 		// (c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";

// 		//no " "
// 		// input<<a <<oper[c] <<b<<"\n";
// 		// (c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";

// 		//reandom " "
// 		// input<<a<< ((rand()%2==1)?" ":"") <<oper[c]<< ((rand()%2==1)?" ":"") <<b<<"\n";
// 		// (c!=3)? output<< cal(c, a, b) <<"\n" : output<< cal(a, b) <<"\n";
// 	}
// 	input<<"EOF";
// 	input.close();
// 	output.close();

// 	return 0;
// } 
