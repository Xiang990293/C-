#include<iostream>
using namespace std;

int main(){
	int n, m, temp;
	int blue[1001];
	// while(scanf("%d %d", &n, &m)){
		scanf("%d %d", &n, &m);
		for(int bookshelf=1; bookshelf<=n; bookshelf++){
			scanf("%d", &temp);
			blue[temp] = bookshelf;
		}

		for(int b=1; b<=m; b++){
			printf("%d ", blue[b]);
		}
		printf("\n");
	// }
}