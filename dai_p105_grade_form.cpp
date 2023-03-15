#include<iostream>
using namespace std;

string grade(float avg){
	int g=avg/10;
	switch(g){
		case 10:
		case 9:
			return "優";
		case 8:
			return "甲";
		case 7:
			return "乙";
		case 6:
			return "丙";
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			return "丁";
	}
}

int main() {
	int n;
    while(cin >> n){
		int sum[5]={0},counter[5]={0},top[5]={0};
		cout<<"座號 國文 英文 數學 自然 社會 總分 平均 等第 不及格科數"<<endl;
		int t=0, sums=0;
		for(int i=1; i<=n; i++){
			sums=0;
			cout<<i<<" ";
			for(int j=0; j<5; j++){
				cin >> t;
				sums+=t;
				cout << t << " ";
			}
			int avg=(float)(10*sums/5)/(float)10;
			cout<<sums<<" "<<avg<<" "<<grade(avg)<<" ";
		}
	}
}