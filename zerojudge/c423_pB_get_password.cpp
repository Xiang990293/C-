#include<iostream>
#include<string>
#include<set>
using namespace std;

static const auto Initialize = [] {
	cin.sync_with_stdio(false); cin.tie(nullptr);
	return nullptr;
}();

inline int find_root(string origin){
	int sum = 0;
	for (char &c : origin)
		sum += (c - '0');
	sum %= 9;
	return sum ? sum : 9;
}

inline int find_root(int origin){
	if (!origin) return 0;

	origin %= 9;
	return origin ? origin : 9;
}

int main(){
    int n, r;
    string password;
	set<string> cand;
	set<string>::iterator ending, now;
	int finded_root;
    while(cin >> n >> r >> password){
        finded_root = find_root(password);
		cand.clear();
        
        for (int j = 0; j < 10; j++)
			if (find_root(j + finded_root) == r)
				for (int i = 0; i < n; i++)
					cand.insert(password.substr(0, i) + char(j + '0') + password.substr(i)); // set insert

        ending = (cand.end());
		now = (cand.begin());
        
        for (now++, ending--; now != ending; now++)
			cout << *now << "\n";
    }
}