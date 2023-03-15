#include<iostream>
using namespace std;

int main() {
	char oper;
	while(cin>>oper){
		int a,b;
		cin >> a >> b;
		switch(oper){
			case '+':
                cout<<a+b<<endl;
                break;
            case '-':
                cout<<a-b<<endl;
                break;
            case '*':
                cout<<a*b<<endl;
                break;
            case '/':
                cout<<(float)a/(float)b<<endl;
                break;
            case '%':
                cout<<a%b<<endl;
		}
	}
}