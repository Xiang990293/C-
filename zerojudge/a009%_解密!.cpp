#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int b = 0;
	//int c = 0;
    char a[1000] = {0};
    int a1[1000] = {0};
    cout << "請輸入文本及偏移量：" << endl;
    while(cin >> a >> b){
		cout << "轉換結果如下：" << endl;
		if (b < 0){
			//向後位移 
			for (int i=0; i<1000; i++){
				if (a[i] != 0 && (int)a[i] >= 126+b){
					a1[i] = (int)(126-a[i]+b+33);
					a[i] = (char)a1[i];
					cout << (char)a[i];	
				}else if (a[i] != 0 && (int)a[i] < 126+b){
					cout << (char)(a[i]-b);
				}
			}
		}else if (b >= 0) { 
			//向前位移 
			for (int i=0; i<1000; i++){
				if (a[i] != 0 && (int)a[i] >= 33+b){
					cout << (char)(a[i]-b);	
				}else if (a[i] != 0 && (int)a[i] < 33+b){
					a1[i] = (int)(a[i]+126-70+b);
					a[i] = (char)a1[i];
					cout << (char)a[i];
				}
			}
		} 
		cout << endl << endl;
		char a[] = {0};
		int a1[] = {0};
		cout << "請輸入文本及偏移量：" << endl; 
    }
    return 0;
}
