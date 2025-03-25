#include<iostream>
using namespace std;

int main(){
	int a,t;
	while(cin>>a>>t){
		int array[a]={};
		for(int i=0;i<a;i++) cin>>array[i];
		int b, s=-1;
		for(int i=0;i<t;i++){
			cin>>b;
			s=-1;
			for(int j=0;j<a;j++) if(b==array[j]){
				s=j;
				cout<<"在索引 " << s<<endl;
				break;
			}
			if(s==-1) cout << "沒有搜尋到資料" << endl;
			cout << "----------" << endl;
		}
	}
}