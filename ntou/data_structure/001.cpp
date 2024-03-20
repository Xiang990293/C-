#include <iostream>
using namespace std;

int main(){
	int grade[6] = {72, 80, 78, 90, 86, 95};

	int sum = 0;

	for(int i=0; i<6; i++){
		sum += grade[i];
	}

	float avg = sum /= 6.0f;

	cout << "Sum= " << sum
	<< ", Average= " << avg << endl;
}