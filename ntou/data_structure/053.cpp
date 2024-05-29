#include"limited_queue.cpp"
using namespace std;

int main(){
	output_limited_queue a;

	cout << "放入" <<endl;
	int mode[7] = {1,2,1,2,1,2,1}; 
	for(int i=20; i<27; i++){
		a.push(i,mode[i-20]);
		cout << "[" << i << "]" << endl; 
	}

	cout << "取出" <<endl;
	for(int i=20; i<27; i++){
		cout << "[" << a.pop() <<  "]" << endl;
	}
}