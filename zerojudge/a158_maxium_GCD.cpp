#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>
using namespace std;

int gcd(int a, int b){
	if(a % b == 0) return b;

	return gcd(b, a % b);
}

int main(){
	int count;
	string line;
	stringstream s;
	int temp;
	getline(cin, line);
	count = stoi(line);
	// scanf("%d", &count);
	for(int i=0; i<count; i++){
		cin.clear();
		getline(cin, line);
		s.str("");
		s.clear();
		s << line;

		vector<int> numbers;

		for(int i=0; s >> temp; i++){
			if(s.fail()) break;
			numbers.push_back(temp);
		}

		int max = 0;
		for(int i=0; i<numbers.size()-1; i++){
			for(int j=i+1; j<numbers.size() && numbers.size() > 1; j++){
				temp = gcd(numbers[i],numbers[j]);
				if(temp > max) max = temp;
			}
		}

		printf("%d\n",max);
	}
}