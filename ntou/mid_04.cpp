#include<iostream>
using namespace std;

int main(){
	bool conti;
	int amount;
	int selected;
	cout << "輸入你投入的金額: ";
	cin >> amount;
	while(true){
		cout << "輸入飲料別(1.可樂15元/瓶 或 2.汽水12元/瓶): ";
		cin >> selected;
		switch(selected){
			case 1:
				if(amount>=15){
					amount -= 15;
					cout << "是否要購買第二件商品(是=1; 否=0)";
					cin >> conti;
				}
				else{
					cout << "餘額不足" << endl;
					conti = false;
				}
				break;
			case 2:
				if(amount>=12){
					amount -= 12;
					cout << "是否要購買第二件商品(是=1; 否=0)";
					cin >> conti;
				}
				else{
					cout << "餘額不足" << endl;
					conti = false;
				}
				break;
			default:
				cout << "選項不存在" << endl;
				break;
		}
		if(!conti) break;
	}
	cout << "您的餘額 " << amount << endl;
	cout << "謝謝惠顧~" << endl;
}