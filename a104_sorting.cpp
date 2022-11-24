#include<iostream>
using namespace std;

int main(){
    int a;
    while(cin>>a){
        int s[a]={};
        for(int i=0; i<a; i++) cin >> s[i];
        for(int i=0; i<a; i++){
            for(int j=a-1; j>i; j--) if(s[j]<s[j-1]){
                int c=s[j];
                s[j]=s[j-1];
                s[j-1]=c;
            }

            cout << s[i];
            if(i!=a-1) cout << " ";
        }
        cout<< endl;
    }
    return 0;
}