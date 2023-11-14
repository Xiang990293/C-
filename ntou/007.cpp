#include<vector>
#include<iostream>
using namespace std;

int main(){
	double step[5];
	double sum = 0;
	for(int i=0; i<5; i++){
		cout << "輸入星期" << i+1 << "的走路步數: ";
		cin >> step[i];
		sum += step[i];
	}
	cout << sum/5.0 << endl;

	// int x, y;
	// vector<int> a, b;
	// while(cin >> x >> y){
	// 	a = vector({x, y});
	// 	cin >> x >> y;
	// 	b = vector({x, y});
	// 	cout << a[0]*b[0] + a[1]*b[1] << endl;
	// }
}