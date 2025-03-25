#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int i=100;
    while(true){
        i+=100;
        int k=0;
        for(int j=0; j<i; j++){
            k+=sqrt((i-j)*j);
        }
        cout << i << ", " << k << endl;
    }
}