#include<iostream>
using namespace std;

int main(){
	int people;
	int people_innocent = 0, people_wolf = 0;
	scanf("%d", &people);
	int work[people+1];
	for(int i=1; i<=people; i++){
		scanf("%d", &work[i]);
		if(work[i] == 0 || work[i] == 1) people_innocent++;
		else people_wolf++;
	}

	int temp;
	while(scanf("%d", &temp)){
		if(temp == 0){
			if(people_wolf != 0) printf("Werewolves\n");
			else printf("Townsfolk\n");
			break;
		}

		if(work[temp] == 0 || work[temp] == 1) people_innocent--;
		else if(work[temp] == -1) people_wolf--;
		else if(work[temp] == -2) {
			printf("Wrong\n");
			while(scanf("%d", &temp)){
				if(temp==0) break;
			}
			break;
		}

		work[temp] = -2;
		
	}
}