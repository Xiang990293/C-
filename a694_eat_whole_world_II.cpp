#include <iostream>
using namespace std;

int main(){
	int m=0,n=0;
	while(cin>>n>>m){
		int food[n][n]={0};
		int v_s[n][n]={0}; //vertical sum
		int h_s[n][n]={0}; //horizontal sum
		//input and calculate horison sum in each raw
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> food[i][j];
				if(j>0){
					h_s[i][j] = food[i][j] + h_s[i][j-1];
				}else{
					h_s[i][j] = food[i][j];
				}
			}
		}
		//calculate ractangle sum in all raws before current one
		for(int i=1; i<n; i++){
			for(int j=n; j>0; j--){
				h_s[i][j]=h_s[i-1][j]+food[i][j]+h_s[i][j-1];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(j>0){
					v_s[j][i] = food[j][i] + v_s[j-1][i];
				}else{
					v_s[j][i] = food[j][i];
				}
			}
		}
		
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){
//				cout << v_s[i][j] << "";
//			}
//			cout << endl;
//		}
		cout << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << h_s[i][j] << "";
			}
			cout << endl;
		}
	}
}
