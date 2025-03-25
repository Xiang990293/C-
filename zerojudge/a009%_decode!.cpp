#include <iostream>
#include <math.h>
using namespace std;

string trans_char(int bias, string a){
	int charset_length = a.length();
    string result;
	if(bias<0) bias += 93;
	if(bias>93) bias -= 93;
	for (int i=0; i<charset_length; i++){
		// cout << ((int)a[i]+bias)%(126+1)+33*((int)(a[i])+bias>126) << ",";
		result += (char)(((int)a[i]+bias)%(126+1)+33*((int)(a[i])+bias>126));
	}

	return result;
}

int main(){
	int b = 0;
	//int c = 0;
    string a;
    cout << "請輸入文本及偏移量\n輸入文本後先按Enter，再輸入偏移量\n偏移量0則輸出所有結果：" << endl;
    while(cin >> a >> b){
		if (b==0) { 
			cout << "轉換結果如下：" << endl;
			for(b=0; b<=93; b++)
				cout << trans_char(b, a) << endl;
		} else { 
			cout << "偏移 " << b << " 的轉換結果如下：" << endl;
			cout << trans_char(b, a) << endl;
		}
		cout << "請輸入文本及偏移量：" << endl; 
    }
    return 0;
}
