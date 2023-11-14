#include<iostream>
#include<string>
using namespace std;

const char stoi_a[10] = {'0','1','2','3','4','5','6','7','8','9'};

int stoi(char a){
    for(int i=0; i<10; i++){
        if(stoi_a[i]==a) return i;
    }

    return -1;
}

int power(int a, int n){
    int b=a;
    for(int i=0; i<n-1; i++){
        b*=a;
    }
    return b;
}

int finder(int a){
    string A=to_string(a);
    int sum=0;
    int n=A.length();
    for(int i=0; i<n; i++){
        sum += power(stoi(A[i]),n);
    }
    if(a==sum)return a;
    else return -1;
}

int main(){
    int max,min;
    while(cin>>min>>max){
        int c=0;
        for(int i=min; i<=max; i++){
            int a=finder(i);
            if(a!=-1){
                c++;
                if(c>1){
                    cout << " ";
                }
                cout << a;
            }
        }
        if(c==0){
            cout << "none";
        }
        cout << endl;
    }
}