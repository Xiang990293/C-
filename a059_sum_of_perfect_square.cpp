#include<iostream>
using namespace std;

const int perfect_square_in_1000[32]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961};

int main(){
    int count=0;
    while(cin>>count){
        int sum=0;
        for(int i=0; i<count; i++){
            int min=0, max=0;
            sum=0;
            cin >> min >> max;
            for(int j=min; j<=max; j++){
                for(int k=0; k<32; k++){
                    if(j==perfect_square_in_1000[k]){
                        sum+=j;
                        break;
                    }
                }
            }

            cout << "Case " << i+1 << ": " << sum << endl;
        }
    }
}