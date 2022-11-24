#include <iostream>
using namespace std;

int main(){
    int x,y,z;

    while(cin >> x >> y >> z){
        int b_turn[y][x]={};
        int exc=0;

        int b[x][y]={};

        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                cin >> b[i][j];
            }
        }

        int op[z]={};
        int rotate_times = 0;
        for(int i=0; i<z; i++){
            cin >> op[i];
            if(op[i]==0){
                rotate_times++;
            }
        }
        
        rotate_times = 0;
        for(int k=z-1; k>=0; k--){
            if(op[k]==1){
                if(rotate_times%2==0){
                    for(int i=0; i<x/2; i++){
                        for(int j=0; j<y; j++){
                            exc = b[i][j];
                            b[i][j] = b[x-i-1][j];
                            b[x-i-1][j] = exc;
                        }
                    }
                }else{
                    for(int i=0; i<y/2; i++){
                        for(int j=0; j<x; j++){
                            exc = b_turn[i][j];
                            b_turn[i][j] = b_turn[y-i-1][j];
                            b_turn[y-i-1][j] = exc;
                        }
                    }
                    
                }
            }else{//op[k]==0
                if(rotate_times%2==0){
                    for(int i=0; i<x; i++){
                        for(int j=0; j<y; j++){
                            b_turn[j][i] = b[i][y-j-1];
                        }
                    }
                }else{
                    for(int i=0; i<y; i++){
                        for(int j=0; j<x; j++){
                            b[j][i] = b_turn[i][x-j-1];
                        }
                    }
                }
                rotate_times++;
            }
        }

        // for(int i=y-1; i>=0; i--){
        //     for(int j=0; j<x; j++){
        //         b[j][i] = b_turn[i][j];
        //     }
        // }

        if(rotate_times%2==0){
            cout << x << " " << y << endl;
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    cout << b[i][j];
                    if(j<y-1){
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }else{
            cout << y << " " << x << endl;
            for(int i=0; i<y; i++){
                for(int j=0; j<x; j++){
                    cout << b_turn[i][j];
                    if(j<x-1){
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
    }
}