#include<iostream>
using namespace std;

int main(){
    int n=0;
    while(cin >> n){
        int a=0;
        int r0=0,r1=0,r2=0;
        for(int i=0; i<n; i++){
            cin >> a;
            switch (a%3){
                case 0:{
                    r0++;
                    break;
                }

                case 1:{
                    r1++;
                    break;
                }

                case 2:{
                    r2++;
                    break;
                }
            }
        }

        cout << r0 << " " << r1 << " " << r2 << endl;
    }
}