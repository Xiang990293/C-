#include <iostream>
using namespace std;

const int rule[6][6]={{2,-1,1,-1,-1,0},{-1,-1,-1,-1,-1,-1},{0,-1,2,-1,-1,1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{1,-1,0,-1,-1,2}};
const int B_rule[6][6]={{5,-1,2,-1,-1,5},{-1,-1,-1,-1,-1,-1},{0,-1,0,-1,-1,5},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{0,-1,2,-1,-1,2}};

int main(){
    int B=0, N=0;

    while(cin >> B >> N){
        int S[N] = {};

        for(int i=0; i<N; i++){
            cin >> S[i];
        }
        bool isEnd = false;
        for(int i=0; i<N && isEnd==false; i++){
            cout << B << " " ;
            switch(rule[B][S[i]]){
                case 1:{
                    cout << ": Won at round " << i+1 << endl;
                    isEnd = true;
                }break;

                case 0:{
                    cout << ": Lost at round " << i+1 << endl;
                    isEnd = true;
                }break;

                case 2:{
                    if(S[i-1]==S[i]){
                        B = B_rule[B][S[i]];
                    }else{
                        B = S[i];
                    }
                }
            }
        }

        if(isEnd==false){
            cout << ": Drew at round " << N << endl;
        }
    }
    
    return 0;
}