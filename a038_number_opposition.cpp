#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    string b;
    while(cin >> a){
        b="";
        for(int i=a.length()-1; i>=0; i--){
            b += a[i];
        }

        int i;
        for(i=0; i<a.length(); i++){
            if(b[0]=='0')b = b.substr(1,-1);
            else break;
        }
        if(b=="")b = "0";

        cout << b << endl;
    }
}