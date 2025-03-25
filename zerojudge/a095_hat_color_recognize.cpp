#include<iostream>
using namespace std;

int main(){
    int all, r;
    while(cin>>all>>r){
        if(all==r) cout << r << endl;
        else cout << r+1 << endl;
    }
    return 0;
}