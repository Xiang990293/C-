#include <iostream>
using namespace std;

int main(){
	int length = 0, width = 0;
	cout << "請輸入長&寬, 且用空格隔開兩者：" << endl << ">> ";
	cin >> length >> width;
	cout << "長為" << length << ", 寬為" << width << "的長方形面積為" << length * width;
}