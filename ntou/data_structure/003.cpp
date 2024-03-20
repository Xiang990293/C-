#include<iostream>
using namespace std;

int main(){
	int grade[2][6] = {{72, 80, 78, 90, 86, 95}, {75, 85, 81, 84, 88, 70}};

	for(int i=0; i<2; i++){
		int sum = 0;
		for(int j=0; j<6; j++){
			sum += grade[i][j];
		}
		cout << "Sum of grade in " << ((i==0)? "A" : "B") << " is: " << sum << endl;
	}
}