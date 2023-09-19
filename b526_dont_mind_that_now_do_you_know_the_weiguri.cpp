#include<iostream>
#include<stack>
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
	int count(){
		return right - left;
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
		for(int i=1; i<m; i++){
			segment *a = &section[i-1];
			segment *b = &section[i];
			short compare = 0b0;
			if((*a).Covering(*b)) compare += 2;
			if((*b).Covering(*a)) compare += 1;

			int temp;
			switch(compare){
				case 0:
					break;
				case 1:
					break;
				case 2:
					temp = (*a).right;
					(*a).right = (*b).left;
					(*b).left = temp;
					break;
				case 3:
					temp = (*a).right;
					(*a).right = (*b).left;
					(*b).left = temp;
					break;
			}

			sort(section, section+m, &sort_segment);
		}
		int count = 0;
		for(int i=0; i<m; i++){
			count += section[i].count();
		}
		cout << count << endl;
	}
}