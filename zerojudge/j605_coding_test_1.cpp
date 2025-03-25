#include<iostream>
#include<algorithm>
using namespace std;

struct submittion{
	int tick;
	int score;
	submittion(){
		tick = 0;
		score = 0;
	}
	submittion(int t, int s){
		tick = t;
		score = s;
	}
	void print(){
		cout << tick << ", " << score << endl;
	}
};

bool sort_tick(submittion a, submittion b){
	return a.tick < b.tick;
}

int main(){
	int n=0;
	while(cin >> n){
		int max_tick = 0, fatel = 0, score = 0;
		submittion test[n];
		int t, s;
		for(int i=0; i<n; i++){
			cin >> t >> s;
			test[i] = submittion(t,s);
		}
		sort(test, test+n, &sort_tick);
		for(int i=0; i<n; i++){
			if(test[i].score>test[max_tick].score) max_tick = i;
			else if(test[i].score == -1) fatel++;
		}
		score = test[max_tick].score - n - fatel*2;
		cout << ((score>=0)?score:0) << " " << test[max_tick].tick << endl;
	}
}