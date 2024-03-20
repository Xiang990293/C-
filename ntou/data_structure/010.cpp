#include<iostream>
using namespace std;

struct Course{
	string name;
	string code;

	Course(){
		name = "";
		code = "N/A";
	}

	Course(string n, string c){
		name = n;
		code = c;
	}

	string out(){
		return name+string(" ")+code;
	}
};

int main(){
	Course courses[9][5] = {
		{Course("機率與統計","B8122T84"),Course(),Course(),Course(),Course()},
		{Course("機率與統計","B8122T84"),Course("工程數學","B8122086"),Course(),Course("流體力學","B8102925"),Course()},
		{Course("線性代數","B8102S60"),Course("工程數學","B8122086"),Course("海洋學","B812103D"),Course("流體力學","B8102925"),Course()},
		{Course("線性代數","B8102S60"),Course("工程數學","B8122086"),Course("海洋學","B812103D"),Course("流體力學","B8102925"),Course()},
		{Course("線性代數","B8102S60"),Course(),Course("陳天裕","B8102N57"),Course("服務學習_愛校","B8101NNY"),Course()},
		{Course(),Course(),Course("陳天裕","B8102N57"),Course(),Course()},
		{Course(),Course(),Course("陳天裕","B8102N57"),Course(),Course()},
		{Course(),Course(),Course(),Course(),Course()},
		{Course(),Course(),Course(),Course(),Course()},
	};

	int sum = 0;
	for(int i=0; i<9; i++){
		for(int j=0; j<5; j++){
			if(courses[i][j].code != "N/A"){
				sum += 1;
			}
		}
	}

	cout << sum << endl;
}