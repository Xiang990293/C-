#include<math.h>
#include<iostream>
#include"chain_list.cpp"
using namespace std;

chain_list prime_factorize(int num){
	chain_list result;

	for(int i = 2; i <= num; i++){
		int count = 0;
		if(num % i != 0){
			continue;
		}
		while(num % i == 0){
			num /= i;
			count++;
		}
		result.push(new node(i, count));
	}

	return result;
}

// int main(){
// 	int n;
// 	while(cin >> n){
// 		cout << prime_factorize(n).print() <<endl;
// 	}
// 	return 0;
// }