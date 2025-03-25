#include<iostream>
using namespace std;

int main(){
    int A[10000];
    int B[10000];
    int b=0, e=0, s=0;
    for(int i=0; i< 10000; i++){
        if(A[i] > B[i]){
            cout << ">";
            b++;
        }else if(A[i] == B[i]){
            cout << "=";
            e++;
        }else if(A[i] < B[i]){
            cout << "<";
            s++;
        }else{
            cout << "find the false ";
        }
        cout << " " << A[i] << " " << B[i] << " " << endl;
    }
    cout << "bigger: " << b << ",equal: " << e << ",small: " << s << endl;
}