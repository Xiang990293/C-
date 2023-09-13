#include<iostream>
#include<stack>
using namespace std;

struct point{
	int x, y;
	point(int a, int b){
		x = a;
		y = b;
	}
	int print(){
		cout << "("<<x<<", "<<y<<")"<<endl;
		return 0;
	}
};

int main(){
	stack<point> D;
	D.push(point (3, 10));
	D.push(point (4, 10));
	D.push(point (1, 7));

	stack E = D;
	for(int i=0; i<E.size(); i++)
	
	return 0;
}