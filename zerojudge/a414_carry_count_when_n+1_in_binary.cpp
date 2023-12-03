#include<iostream>
#include<bitset>
using namespace std;

int main(){
	int decimal;
	int count = 0;
	while(scanf("%d",&decimal)){
		if(decimal == 0) break;

		bitset<32> binary(decimal);
		for(count = 0; binary[count] != 0; count++);
		printf("%d\n",count);
	}

	// while(scanf("%d",&decimal) && decimal) 
	// 	printf("%d\n",__builtin_ctz(~decimal));
}