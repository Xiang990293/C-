#include<iostream>
using namespace std;

int main(){
	// 12. (1)
	for(int i=0; i<n; i++){			//n+1次 
		for(int j=0; j<n; j++){		//n(n+1)次 
			for(int k=0; k<n; k++){	//n2(n+1)次 
				a = a + 1;          //n¬3次 
			}                       //時間複雜度為O(n¬3)
		}
	}

	// 12. (2)
	int i = 1;       //1
	while(i <= n){   //n+1
		a = a + 1;   //n
		i++;         //n
	}                //時間複雜度為O(n)

	// 12. (3)
	void n2n(int n){                          //
		int i;                                //
		int total;                            //
		total = 0;                            //
		for(int i=1; i<=n; i++){              //
			printf("數字: %d\n", i);          //
			total += i;                       //
		}
		printf("從一到五的總和: %d\n", total); //
	}
}