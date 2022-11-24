#include <iostream>
using namespace std;

int main(){
    int s=0, t=0, m=0, n=0, r=0;
    while(cin >> s >> t >> m >> n >> r){
        int a[s][t]={0},b[m][n]={0};
        int as=0;
        for(int i=0; i<s; i++){
            for(int j=0; j<t; j++){
                cin >> a[i][j];
                as += a[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> b[i][j];
            }
        }
        int count=0, diff=2147483647;
        for(int i=0; i<m-s+1; i++){
            for(int j=0; j<n-t+1; j++){
                int d=0;
                int sumB=0;
                for(int k=0; k<s; k++){
                    for(int l=0; l<t; l++){
                        if(a[k][l]!=b[i+k][j+l]){
                            d++;
                        }
                        sumB+=b[i+k][j+l];
                    }
                }
                if(d<=r){
                    count++;
                    if(abs(sumB-as) < diff){
                        diff = abs(sumB-as);
                    }
                }
            }
        }
        if(count==0){
            cout << count << endl << -1 << endl;
        }else{
            cout << count << endl << diff << endl;
        }

        return 0;
    }
}