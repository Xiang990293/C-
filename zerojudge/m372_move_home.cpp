#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

struct node{
	int x;
	int y;
	bool left;
	bool right;
	bool up;
	bool down;

	node(int x1, int y1, bool l, bool r, bool u, bool d){
		x = x1;
		y = y1;
		left = l;
		right = r;
		up = u;
		down = d;
	}

	node(){
		x = -1;
		y = -1;
		left = 0;
		right = 0;
		up = 0;
		down = 0;
	}

	string get_xy(){
		stringstream result;
		string returning;
		result << x << " " << y;
		getline(result, returning);
		return returning;
	}
};

node to_node(int x, int y, char a){
	if(a == '0') return node();

	switch(a){
		case 'F':{
			return node(x, y, 0, 1, 0, 1);
		}
		case 'H':{
			return node(x, y, 1, 1, 0, 0);
		}
		case '7':{
			return node(x, y, 1, 0, 0, 1);
		}
		case 'I':{
			return node(x, y, 0, 0, 1, 1);
		}
		case 'X':{
			return node(x, y, 1, 1, 1, 1);
		}
		case 'L':{
			return node(x, y, 0, 1, 1, 0);
		}
		case 'J':{
			return node(x, y, 1, 0, 1, 0);
		}
	}

}

bool connect_check(node* a, node* b){
	if ((abs(a->x - b->x) + abs(a->y - b->y)) == 1) return false; // check the distance (Manhattan distance)
	if (a->x == b->x) return (a->left&&b->right)||(a->right&&b->left);
	if (a->y == b->y) return (a->up&&b->down)||(a->down&&b->up);
}

bool node_check(node* a){
	return a->x >= 0;
}

int main(){
	int row, column;
	while(cin >> row >> column){
		char temp;
		node map[row][column];
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++){
				cin >> temp;
				map[i][j] = to_node(i, j, temp);
			}
		
		node* current = &map[0][0];
		int max = 0;
		while(current->x + current->y < row+column-2){
			bool out = false;
			for(int i = 0; i < row || out; i++)
				for(int j = 0; j < column || out; j++){
					if (node_check(&map[i][j])) {
						current = &map[i][j];
						out = true;
					}
				}
			
			;
		}

		std::cout << max << endl;
	}
}