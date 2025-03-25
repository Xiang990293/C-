#include<iostream>
#include<sstream>
using namespace std;

int find_root(int orgin){
	stringstream nums;
	char digit = 0;

	nums << orgin;
	int sum = 0;
	while(true){
		nums >> digit;
		if(nums.fail()) break;

		sum += int(digit) - 48;

		if(sum/10>0) return find_root(sum);
	}
	
	return sum;
}

int main(){
	int n, r, password;
	int root;
	while(cin >> n >> r >> password){
		root = find_root(password);
		cout << root << endl;
	}
}