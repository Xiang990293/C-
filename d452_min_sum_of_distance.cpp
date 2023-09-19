#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
	int n, m;
	while(cin >> n){
		for(int i=0; i<n; i++){
			cin >> m;
			int data[m], middle;
			int sum=0;
			for(int j=0; j<m; j++) cin >> data[j];
			sort(data, data+m);
			middle = floor(m/2);
			middle = data[middle];
			for(int j=0; j<m; j++){
				sum += abs(data[j] - middle);
			}
			cout << sum << endl;
		}
	}
}