#include<iostream>
using namespace std;

int main(){
	int n,a1,a2,a3,a4;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a1>>a2>>a3>>a4;
			cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" ";
			if(a4-a3==a3-a2&&a3-a2==a2-a1)cout<<a4+a4-a3<<endl;
			else cout<<a4*a4/a3<<endl;
		}
	}
}
