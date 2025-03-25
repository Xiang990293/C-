#include <iostream>
#include <vector>
using namespace std;

struct matrix{
	vector<float> row;
	vector<vector<float>> column;
	vector<float> *r = &row;
	vector<vector<float>> *c = &column;
	matrix(int row, int column){
		for(int i = 0; i<row; i++){
			vector<float> *t = r+i;
			t[i] = 0;
		}

	}
};

int main(){
	int a = 10;
	int *b = &a;
	cout << a << " " << b << " " << *b;
}