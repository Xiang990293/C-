#include<iostream>
using namespace std;

int cut_count(int n){
    if(n==0) return 1;
    else return cut_count(n-1)+n;
}

int count(int n){
    if(n==0) return 1;
    else return count(n-1)+cut_count(n-1);    
}

int main(){
    int n=0;
    while(cin >> n){
        cout << count(n)<< endl;
    }
}