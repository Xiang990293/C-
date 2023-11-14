#include<iostream>
using namespace std;

int main(){
	int x = 2, y = -3;
	if(x > 0){
		if(y > 0){
			cout << "第一象限" << endl;
		}else if(y < 0){
			cout << "第四象限" << endl;
		}
	}else if(x < 0){
		if(y > 0){
			cout << "第二象限" << endl;
		}else if(y < 0){
			cout << "第三象限" << endl;
		}
	}
}