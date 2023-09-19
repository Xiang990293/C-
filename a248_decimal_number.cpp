#include <iostream>
#include <string>
using namespace std;

int main(){
	int dived, diver, n, i;
	string ans;
	while(cin >> dived >> diver >> n){
		ans = to_string(dived / diver);
		if (n==0){
			cout << ans << endl;
			continue;
		}
		ans += ".";
		for(i=0; i<n; i++){
			dived = 10*(dived % diver);
			ans += to_string(dived / diver);
		}
		cout << ans << endl;
	}

	return 0;
}
