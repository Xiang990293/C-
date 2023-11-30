#include<iostream>
#include<queue>
using namespace std;

int main(){
	int count;
	while(cin >> count){
		queue<int> a;
		int move;
		for(int i=0; i<count; i++){
			cin >> move;
			int element;
			switch(move){
				case 1:
					cin >> element;
					a.push(element);
					break;
				case 2:
					if(a.size()!=0) cout << a.front() << endl;
					else cout << -1 << endl;
					break;
				case 3:
					if(a.size()!=0) a.pop();
					break;
			}
		}
	}
}