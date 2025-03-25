#include<iostream>
using namespace std;

int main(){
	float s[8] = {2000,0,0,0,0,0,0,0};
	for(int i=1; i<8; i++){
		s[i] = s[i-1] * 0.9;
		cout << "第" << i << "天水量為" << s[i] << "公噸" << endl;
	}
}