#include<iostream>
using namespace std;

const int date_start[12] = {21,20,21,21,22,22,23,22,24,24,23,23};
const string type[13] = {
	"摩羯座",
	"水瓶座",
	"雙魚座",
	"牡羊座",
	"金牛座",
	"雙子座",
	"巨蟹座",
	"獅子座",
	"處女座",
	"天秤座",
	"天蠍座",
	"射手座",
	"摩羯座"
};

int main(){
	int m, d;
	while(scanf("%d/%d",&m, &d) == 2){
		cout << type[m+(d>=date_start[m-1])-1] << endl;
	}
}	