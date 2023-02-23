#include <iostream>
using namespace std;

int main(){
	int m=0,n=0;
	while(cin>>n>>m){
		int food[n][n]={0};
		int s[n][n]={0}; //rac_sum
		//input and calculate horison sum in each raw
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> food[i][j];
				if(j>0){
					s[i][j] = food[i][j] + s[i][j-1];
				}else{
					s[i][j] = food[i][j];
				}
			}
		}
		
		for(int i=1; i<n; i++){
			for(int j=n-1; j>=0; j--){
				if(j>0) s[i][j]=s[i-1][j]+food[i][j]+s[i][j-1];
				else s[i][j]=s[i-1][j]+food[i][j];
			}
		}
		
		int x1=0,y1=0,x2=0,y2=0;
		int x_yes = 1, y_yes = 1;
		for(int i=0; i<m; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			x_yes = 1, y_yes = 1;
			x1--;
			x2--;
			y1--;
			y2--;
			if(x1==0) x_yes = 0;
			if(y1==0) y_yes = 0;
			cout << s[x2][y2] - x_yes*s[x1-1][y2] - y_yes*s[x2][y1-1] + x_yes*y_yes*s[x1-1][y1-1] << endl;
		}		
	}
}
