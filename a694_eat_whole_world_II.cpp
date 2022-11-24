#include <iostream>
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m){
        int vertical_array[n+1][n];
        int horizontal_array[n][n+1];
        vertical_array[0][0]=0;
        horizontal_array[0][0]=0;
        for(int k=1;k<=n;k++){
            horizontal_array[0][k]=horizontal_array[n-1][k];
            for(int l=1;l<=n;l++){
                int nnfood;
                cin >> nnfood;
                horizontal_array[l][k]=nnfood+horizontal_array[l-1][k];
            }
        }
        for(int k=0;k<m;k++){
			int i,j;
			cin>>i>>j;
			cout<<""<<endl;
        }
    }
}
