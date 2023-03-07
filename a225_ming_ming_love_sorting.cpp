#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    if (a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int main() {
	int n;
	while(cin >> n) {
		int temp=0;
		vector<vector<int>> number(2, vector<int>(1000));
		for(int i=0; i<n; i++) {
			cin >> temp;
			number[0][i] = temp/10;
			number[1][i] = temp%10;
		}

		vector<int> idx(n);
		for (int i = 0; i < n; i++) idx[i] = i;

		sort(idx.begin(), idx.end(), [&](int a, int b){
			return number[0][a] < number[0][b];
		});

		stable_sort(idx.begin(), idx.end(), [&](int a, int b){
			return number[1][a] > number[1][b];
		});

		for (int i = n-1; i >= 0; i--){
			if (i<n-1) cout << " ";
			cout << 10*number[0][idx[i]]+number[1][idx[i]];
		}
		cout << endl;
		
	}
}