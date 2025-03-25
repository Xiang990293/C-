#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int count;
	int set;
	while(cin >> count){
		if(count == 0) break;
		set++;
		cout << "Set #" << set << endl;

		int bricks[count] = {};
		int avg = 0;
		for(int i=0; i<count; i++){
			cin >> bricks[i];
			avg += bricks[i];
		}
		avg /= count;

		int brick_counts=0;
		sort(bricks, bricks+count);
		while(bricks[0]!=avg){
			bricks[0]+=1;
			sort(bricks, bricks+count, greater<int>());
			bricks[0]-=1;
			sort(bricks, bricks+count);
			brick_counts++;
			// for(int i=0; i<count; i++) cout << bricks[i] << " ";
			// cout << endl;
		}

		cout << "The minimum number of moves is " << brick_counts << "." << endl;
	}
}