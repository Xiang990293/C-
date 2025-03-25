#include"prime_factorize.cpp"
using namespace std;

int add_up_all_factor(chain_list chain){
	int result = 1;
	while (chain.length != 0) {
		int prime = chain.start->next->prime;
		int count = chain.start->next->count;
		int sum = 0;
		int power = 1;
		for(int i=0; i<=count; i++){
			sum+=power;
			power*=prime;
		}
		result*=sum;

		chain.delete_node(0);
	}

	return result;
}

int main(){
	int max;
	while(cin >> max){
		for(int i=1; i<=max; i++) {
			cout << i << ": " << add_up_all_factor(prime_factorize(i))-i << endl;
		}
	}
}