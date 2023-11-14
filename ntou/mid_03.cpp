#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int half = 500;
	float remain = 0;
	cout << "輸入剩餘元素數量(總量1000000): ";
	cin >> remain;
	remain /= (float)1000000;
	remain = log10(remain)/log10(0.5);
	remain *= 500;
	cout << "此物質經過" << remain <<"年的衰變";
}