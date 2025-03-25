#include<iostream>
using namespace std;

int main(){
    int n=0;
    while(cin >> n){
        if(n<10) cout << 6*n << endl;
        else if(n<=20) cout << 60+2*(n-10) << endl;
        else if(n<=40) cout << 60+20+(n-20) << endl;
        else cout << 100 << endl;
    }

    return 0;
}