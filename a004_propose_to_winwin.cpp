#include<iostream>
using namespace std; int main(){int y;while(cin>>y){if(y%400==0)cout<<"閏年"<<endl;else if(y%100==0)cout<<"平年"<<endl;else if(y%4==0)cout<<"閏年"<<endl;else cout<<"平年"<<endl;}}