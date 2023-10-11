#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class rabbit{
public:
	int weight;
	int poison_level;
	rabbit(int w){
		weight = w;
		poison_level = 0; 
	}
};

int main(){
	int dimension;
	int xyzw[5]={0,0,0,0,0}, poison, weight;
	int i,  j;
	while(true){
		if(scanf("%d",&dimension) != 1){
			break;
		}

		for(i = 0; i < dimension; i++){
			scanf("%d %d %d %d %d %d",&xyzw[1], &xyzw[2], &xyzw[3], &xyzw[4], &poison, &weight);
			rabbit tommy(weight);
		}
	}
}