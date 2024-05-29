#include"queue.cpp"
using namespace std;

int main(){
	queue a;

	cout << "放入" <<endl;
	for(int i=20; i<32; i++){
		a.push(i);
		cout << "[" << i << "]" << endl; 
	}

	cout << "取出" <<endl;
	for(int i=20; i<32; i++){
		cout << "[" << a.pop() <<  "]" << endl;
	}
}