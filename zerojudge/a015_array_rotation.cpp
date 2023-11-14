#include<iostream>
using namespace std;

int main()
{
	int n;
	int a,b;
	while( cin >> a >> b ){
		int n[a][b];
		
		for(int i=0; i<a; i++){
			for(int j=0; j<b; j++){
				cin >> n[i][j];
			}
		}
		
		for(int i=0; i<b; i++){
			for(int j=0; j<a; j++){
				cout << n[j][i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
