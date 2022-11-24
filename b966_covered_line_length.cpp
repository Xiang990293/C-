#include <iostream>
using namespace std;

int main(){
    int a;
    
    while(cin >> a){
        int L=0;
        int line[a][2]={};
        for(int i=0; i<a; i++){
            cin >> line[i][0] >> line[i][1];
            for(int j=i; j>=0; j--){
                if(line[j-1][0]!=line[j-1][1]||line[j][0]!=line[j][1]){
                    if(line[j][0]<line[j-1][0]){
                        if(line[j][1]>=line[j-1][0]&&line[j][1]<=line[j-1][1]){
                            line[j-1][0] = line[j][0];
                            line[j][1] = line[j][0];
                            break;
                        }else if(line[j][1]>line[j-1][1]){
                            line[j-1][0] = line[j][0];
                            line[j-1][1] = line[j][1];
                            line[j][1] = line[j][0];
                            break;
                        }
                    }else if(line[j][0]==line[j-1][0]){
                        if(line[j][1]<=line[j-1][1]){
                            line[j][1] = line[j][0];
                            break;
                        }else{
                            line[j-1][1] = line[j][1];
                            line[j][1] = line[j][0];
                            break;
                        }
                    }else{
                        if(line[j][0]<=line[j-1][1]){
                            if(line[j][1]<=line[j-1][1]){
                                line[j][1] = line[j][0];
                                break;
                            }else{
                                line[j-1][1] = line[j][1];
                                line[j][1] = line[j][0];
                                break;
                            }
                        }
                    }
                }else if(line[j-1][0]==line[j-1][1]){
                    line[j-1][0] = line[j][0];
                    line[j-1][1] = line[j][1];
                    line[j][0] = line[j][1] = 0;
                }
                for(int j=0; j<a; j++){
                    cout << j+1 << ": " << line[j][0] << " " << line[j][1] << endl;
                }
            }
        }
        for(int i=0; i<a; i++){
            L += line[i][1] - line[i][0];
        }
        cout << L << endl;
    }
}