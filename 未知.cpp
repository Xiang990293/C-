#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	while(cin >> a >> b >> c){
		int m[a][b];
		int m0[a][b];
		for(int i=0; i<a ; i++){
			for (int j=0; j<b; j++){
				cin >> m[i][j];
			}
		}
		for(int i=0; i<c; i++){
			int x;
			cin >> x;
			if(x == 0){
				int m0[b][a];
				for(int i=0; i<a; i++){
					for(int j=0; j<b; j++){
						m0[j][i] = m[i][j];
					}
				}
			}else if(x == 1){
				int m0[a][b];
				for(int i=0; i<a; i++){
					for(int j=b; j>0; j++){
						m0[i][b-j] = m[i][j];
					}
				}
			}
		}
		if(x==1){
			for(int i=0; i<a; i++){
				for(int j=0; j<b; j++){
					
				}
			}
		}else if(x==0){
			for(int i=0; i<a; i++){
				for(int j=0; j<b; j++){
					
				}
			}
		}
	}
	return 0;
}
