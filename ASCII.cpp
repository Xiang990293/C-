#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a = 0;
    cout << "請輸入值：" << endl;
    while(cin >> a){
    	cout << "轉換結果如下：" << endl;
		cout << (char)a << endl;
		cout << "請輸入值：" << endl; 
    }
    return 0;
}
