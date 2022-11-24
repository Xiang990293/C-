#include <iostream>
using namespace std;

const char romenum[7] = {'M','D','C','L','X','V','I'};
const int arabnum[7] = {1000,500,100,50,10,5,1};

int convertA(string x){
	int xr = 0;
	int xl = x.length();
	int xa[xl]={0};
	
	for (int i = 0; i < xl; i++) for (int j = 0; j < 7; j++) if (x[i] == romenum[j]){
		xa[i] = arabnum[j];
		break;
	}
	
	if (xl>1){
		for (int i = 1; i < xl; i++){
			if (xa[i]>xa[i-1]){
				xr += (xa[i] - xa[i-1])
				i++;
				if(i==xl) break;
				else if(i==xl-1) xr += xa[i];
			}else{
				xr += xa[i-1];
				if(i==xl-1) xr += xa[i];
			}
		}
	}
	else xr = xa[0];
	
	return xr;
}

string convertR(int x){
	int num[4] = {x/1000,x/100-10*(x/1000),x/10-10*(x/100),x/1-10*(x/10)};
	string R = "";
	
	for (int i=0; i<num[0]; i++) R += "M";
	
	if (num[1]%5==4){
		R += "C";
		if (num[1]==4) R += "D";
		else if (num[1]==9) R += "M";
	}else{
		if (num[1] >= 5) R += "D";
		for (int i=0; i<num[1]%5; i++) R += "C";
	}
	
	if (num[2]%5==4){
		R += "X";
		if (num[2]==4) R += "L";
		else if (num[2]==9) R += "C";
	}else{
		if (num[2] >= 5) R += "L";
		for (int i=0; i<num[2]%5; i++) R += "X";
	}
	
	if (num[3]%5==4){
		R += "I";
		if (num[3]==4) R += "V";
		else if (num[3]==9) R += "X";
	}else{
		if (num[3] >= 5) R += "V";
		for (int i=0; i<num[3]%5; i++) R += "I";
	}
	
	return R;
}

int main(){
	
	string a, b;
	
	while (cin >> a ){
		if (a == "#") break;
		cin >> b;
		if (b == "#") break;
		
		int result = convertA(a) - convertA(b);
		
		if(result==0) cout << "ZERO" << endl;
		else if(result<0) cout << convertR(-1*result) << endl;
		else cout << convertR(result) << endl;
	}
}
