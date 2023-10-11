#include<iostream>
#include<vector>
#include<math.h>
#include<complex>
#include<regex>
#include<sstream>
using namespace std;

vector<double> add(vector<double> v1, vector<double> v2) {
	int size = v1.size();
	double sum[size];

    for (int i = 0; i < size; i++) sum[i] = (v1[i] + v2[i]);

	vector<double> s(sum, sum+size);

    return s;
}

int main(){
	istringstream s;
	// string str;
	string replacement;
	int sum;09
	// s >> str;
	// while(str!=""){
		sum = 0;
		smatch match1;
		string str = "45 }45 1a6f 6 65afd 15s 1sa 12 115 11{";
		regex_search(str, match1, regex ("(^| )\\b([0-9]+)\\b($| )"));
		cout << match1[0] << endl;
		cout << match1[1] << endl;
		cout << match1[2] << endl;
		cout << match1[3] << endl;
		cout << match1[4] << endl;
		cout << match1[5] << endl;
		s >> str;
	// }

	return 0;
}