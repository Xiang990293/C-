#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int count;
	while(cin >> count){
		int min, max, sum;
		for(int i=0; i<count; i++){
			cin >> min >> max;
			sum = 0;
			min = ceil(sqrt(min));
			max = floor(sqrt(max));
			for(int i=min; i<=max; i++){
				sum += i * i;
			}

			cout << "Case " << i+1 << ": " << sum << endl;
		}
	}
}