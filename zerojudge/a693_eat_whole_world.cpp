#include <iostream>
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m){
        int sumarray[n+1];
        sumarray[0]=0;
        for(int k=1;k<=n;k++){
			int nfood;
			cin >>nfood;
			sumarray[k]=sumarray[k-1]+nfood;
        }
        for(int k=0;k<m;k++){
			int i,j;
			cin>>i>>j;
			cout<<sumarray[j]-sumarray[i-1]<<endl;
        }
    }
}
