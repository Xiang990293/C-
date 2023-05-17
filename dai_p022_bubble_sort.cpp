#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int a[n]={};
		for(int i=0; i<n; i++){
			cin>>a[i];
			cout << a[i] << ((i==n-1)?"":" ");
		}
		cout << endl;
		for(int i=0; i<n-2; i++){
			bool is_done = true;
			for(int j=0; j<n-i-1; j++) if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				is_done = false;
			}
			for(int i=0; i<n; i++) cout << a[i] << ((i==n-1)?"":" ");
			cout << endl;
		}
		cout << "排序好的陣列為" << endl;
		for(int i=0; i<n; i++) cout<< a[i] << ((i==n-1)?"":" ");
		cout << endl;
	}
}