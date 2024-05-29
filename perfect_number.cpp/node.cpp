using namespace std;

struct node{
	int prime;
	int count;
	node* next;

	node(int primei, int counti){
		prime = primei;
		count = counti;
		next = nullptr;
	}
};