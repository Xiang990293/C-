#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(){
	stringstream str;
	string s;
	string s2;
	int xyzwnm[6] = {};
	while(getline(cin, s)){
		int point = 0;
		char now = ' ';
		string result = "";
		cout << s << endl;
		for(int i=0; i<s.length(); i++){
			now = s[i];
			if(now!=' '){
				result += s[i];
			}else{
				cout << result << " " << point << endl;
				xyzwnm[point] = stoi(result);
				if(point==5) xyzwnm[point] = stoi(result);
				point++;
				result = "";
				continue;
			}
		}
		cout
		<< "x:" << xyzwnm[0]
		<< "y:" << xyzwnm[1] 
		<< "z:" << xyzwnm[2]  
		<< "w:" << xyzwnm[3]
		<< "n:" << xyzwnm[4] 
		<< "m:" << xyzwnm[5] 
		<< endl;
		str.clear();
		str << s2;
		int a, b = 0;
		while(str >> a){
			b+=a;
		}
		cout << b << endl;
	}
}
