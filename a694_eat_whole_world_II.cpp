#include <iostream>
using namespace std;

int main(){
	int m=0,n=0;
	int food[505][505]={0};
	int s[506][506]={0};
	while(cin>>n>>m){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> food[i][j];
				s[i+1][j+1] = food[i][j] + s[i+1][j] + s[i][j+1] - s[i][j];
			}
		}
		
		int x1=0,y1=0,x2=0,y2=0;
		for(int i=0; i<m; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			cout << s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1] << endl;
		}
	}
}
