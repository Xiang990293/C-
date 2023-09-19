#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct segment{
	int left, right;
	segment(){
		left=0;
		right=0;
	}
	segment(int l, int r){
		left=l;
		right=r;
	}
	bool Covering(segment b){
		return ((b.left>=left&&b.left<right)||((b.right>left&&b.right<=right)))?true:false;
	}
};

bool sort_segment(segment a, segment b){
	if(a.left!=b.left) return a.left < b.left;
	return a.right < b.right;
}

int main(){
	long long n, m, l, r;
	while(cin >> n){
		cin >> m;
		segment section[m];
		for(int i=0; i<m; i++){
			cin >> l >> r;
			section[i] = segment(l, r);
		}
		sort(section, section+m, &sort_segment);

		cout << endl;
	}
}