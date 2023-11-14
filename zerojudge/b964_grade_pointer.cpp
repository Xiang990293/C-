#include <iostream>
using namespace std;

int main(){
    int stud;
    int min=-1,max=101;
    int con=0;
    while(cin >> stud){
        int gra[stud]={};

        for(int i=0; i<stud; i++){
            gra[i] = 0;
        }

        for(int i=0; i<stud; i++){
            cin >> gra[i];
            for(int j=i; j>0; j--){
                if(gra[j]<gra[j-1]){
                    con = gra[j];
                    gra[j] = gra[j-1];
                    gra[j-1] = con;
                }
            }
        }
        for(int i=0; i<stud; i++){
            cout << gra[i];
            if(i<stud-1){
                cout << " ";
            }
        }
        cout << endl;

        for(int i=0;gra[i]<60;i++){
            if(gra[i]>min){
                min = gra[i];
            }
        }
        for(int j=stud-1;gra[j]>=60;j--){
            if(gra[j]<=max){
                max = gra[j];
            }
        }

        if(min==-1){
            cout << "best case" << endl;
        }else{
            cout << min << endl;
        }
        if(max==101){
            cout << "worst case" << endl;
        }else{
            cout << max << endl;
        }
    }
}