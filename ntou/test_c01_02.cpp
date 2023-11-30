#include<iostream>
#include<cmath>
using namespace std;

float standard(float *data, int sizeOfArray, float avg){
	float var = 0;
	for(int i=0; i<sizeOfArray; i++){
		float temp = ((*(data + i)) - avg);
		var += temp * temp;
	}
	var /= sizeOfArray;
	return sqrt(var);
}

void standarize(float *data, int sizeOfArray, float avg, float strd){
	cout << "標準化結果：" << endl;
	for(int i=0; i<sizeOfArray; i++){
		*(data+i) = ((*(data+i))-avg)/strd;
		cout << *(data+i) << ", ";
	}
	cout << endl;
}

int main(){
	float stud[5] = {163,165,167,171,174};
	float sum = 0, avg = 0;
	for(int i=0; i<5; i++){
		sum += stud[i];
	}
	avg = sum / 5;
	float strd = standard(stud, 5, avg);

	cout << "標準差為：" << strd << endl;
	standarize(stud, 5, avg, strd);
}