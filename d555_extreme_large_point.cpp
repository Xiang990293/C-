#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct point{
	int x;
	int y;
	int print(){
		cout << "(" << x << "," << y << ")" << endl;

		return 0;
	}
};

bool sorting_x(point const& a, point const& b){
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main(){
	int c;
	int casen = 0;
	while(cin>>c){
		casen++;
		cout << "Case " << casen << ":" << endl;
		point a[c];
		stack<point> Dominate;
		for(int i=0; i<c; i++){
			cin >> a[i].x >> a[i].y;
		}
		sort(a, a+c, &sorting_x);
		Dominate.push(a[0]);
		
		for(int i=1; i<c; i++){
			int size = Dominate.size();
			for(int j=0; j<size; j++){
				if(a[i].y>=Dominate.top().y) Dominate.pop();
			}
			Dominate.push(a[i]);
		}

		stack<point> reverse;
		int size = Dominate.size();
		cout << "Dominate Point: " << size << endl;
		for(int i=0; i<size; i++){
			reverse.push(Dominate.top());
			Dominate.pop();
		}
		for(int i=0; i<size; i++){
			reverse.top().print();
			reverse.pop();
		}
	}
	return 0;
}