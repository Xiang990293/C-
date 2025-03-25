#include"limited_queue.cpp"
using namespace std;

int main(){
	input_limited_queue a;

	cout << "放入" <<endl;
	for(int i=20; i<28; i++){
		a.push(i);
		cout << "[" << i << "]" << endl; 
	}

	cout << "取出" <<endl;
	int mode[8] = {1,2,2,1,2,1,1,2}; 
	for(int i=20; i<28; i++){
		cout << "[" << a.pop(mode[i-20]) <<  "]" << endl;
	}
}