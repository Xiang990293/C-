#include <iostream>
using namespace std;

int main(){
	int x1=0,y1=0,x2=0,y2=0;
	while(cin>>x1>>y1>>x2>>y2){
		cout << (x2-x1)*(x2-x1) << " " << (y2-y1)*1 << " " << -2*(y2-y1)*1*x1 << " " << y1+x1*x1*(y2-y1);
	}
}
