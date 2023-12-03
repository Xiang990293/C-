#include<iostream>
using namespace std;

int main(){
	int number;
	while(cin >> number){
		int sum = 0;
		for(int i = 1; i< number; i++){
			sum += (number % i == 0)? i : 0;
		}
		if(sum > number) cout << "盈數" << endl;
		else if(sum < number) cout << "虧數" << endl;
		else if(sum = number) cout << "完全數" << endl;
	}
}