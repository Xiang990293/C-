#include<iostream>
using namespace std;

int count(int n){
    if(n==0) return 1;
    else if(n==1) return 2;
    else return count(n-1)+(n-1)*2;    
}

int main(){
    int n=0;
    while(cin >> n){
        cout << count(n)<< endl;
    }
}