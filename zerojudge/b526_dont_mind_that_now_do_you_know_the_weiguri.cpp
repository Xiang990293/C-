#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int i=0;
int temp;
	bool returnment;
struct segment{
	int left, right;

	segment() : left(0), right(0) {}
    segment(int l, int r) : left(l), right(r) {}

	int count(){
		if(left==-1 || right==-1) return 0;
		return right - left + 1;
	}
	bool Covering(segment *b){
		if(right<(*b).left) return true;
		returnment = false;
		
		if((*b).right<right){
			temp = right;
			right = (*b).left-1;
			(*b).left = (*b).right+1;
			(*b).right = temp;
		}
		else{
			temp = right;
			right = (*b).left-1;
			(*b).left = temp+1;
		}

		if(left>right){
			left = -1;
			right = -1;
			returnment = true;
		}

		if((*b).left>(*b).right){
			(*b).left = -1;
			(*b).right = -1;
			returnment = true;
		}

		return returnment;
	}
	void print(){
		cout << left << ", " << right << endl;
	}
};

bool sort_segment(segment a, segment b){
	if(a.left!=b.left) return a.left < b.left;
	return a.right < b.right;
}

int main(){
	long long n, m, l, r;
	int start = 0;
	int push_start = 0;
	while(cin >> n){
		cin >> m;
		stack<segment> section_s;
		segment section[m+1];
		for(i=0; i<m; i++){
			cin >> l >> r;
			section[i] = (r>=l)?segment(l, r):segment(r, l);
		}
		section[m] = segment(1, n);

		sort(section, section+m+1, &sort_segment);

		bool all_non = false;
		for(i=1; i<=m; i++){
			push_start = 0;
			all_non = false;
			if((section[i-1]).Covering(&section[i])){
				if(section[i].left==-1) push_start++;
				if(section[i-1].left==-1) push_start++;
				else{
					section_s.push(section[i-1]);
					push_start++;
				}
				if(section[i].left==-1 && section[i-1].left==-1) all_non = true;
			}else{
				section_s.push(section[i-1]);
			}
			sort(section+start, section+m+1, &sort_segment);
			start+=push_start;
			if(push_start==2) i++;
		}
		if(!all_non) section_s.push(section[m]);
		
		int count = 0;
		int size_s = section_s.size();
		for(int i=0; i<size_s; i++){
			count += section_s.top().count();
			section_s.pop();
		}
		cout << count << endl;
	}
}