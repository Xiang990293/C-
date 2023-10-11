#include<iostream>
using namespace std;

bool avalible_a[4] = {};
bool avalible_b[4] = {};

void truefill(bool *arr){
	for(int i=0; i<4; i++) *(arr+i) = 1;
}

int main(){

	int a[4], t;
	int i, r, c;
	while(true) {
		if (scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]) != 4) {
			break;
		}
		scanf("%d", &t);
		int b[4], p = 0, q = 0;
		for(i=0; i<t; i++){
			truefill(avalible_a);
			truefill(avalible_b);
			scanf("%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);
			p = 0;
			q = 0;

			for(c=0; c<4; c++){
				if(a[c] == b[c]){
					p++;
					avalible_a[c] = false;
					avalible_b[c] = false;
				}
			}
			
			for(r=0; r<4; r++){
				for(c=0; c<4; c++){
					if(r != c && a[r] == b[c] && avalible_b[c] && avalible_a[r]){
						q++;
						avalible_a[r] = false;
						avalible_b[c] = false;
						break;
					}
				}
			}

			printf("%dA%dB\n",p,q);
		}
	}
}