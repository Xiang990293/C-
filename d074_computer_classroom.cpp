#include<iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int max=-1;
		int temp;
		for(int i=0; i<n; i++){
			cin >> temp;
			if(temp>max) max=temp; 
		}
		cout << max << endl;
	}
}