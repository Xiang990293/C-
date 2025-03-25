#include<iostream>
using namespace std;

int covid101(int day){
    if(day==1) return 1;
    else return covid101(day-1)+day*day-day+1;
}

int main(){
    int day=0;

    while(cin>>day){
        cout << covid101(day) << endl;
    }

    return 0;
}