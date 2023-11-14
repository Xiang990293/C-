#include<iostream>
using namespace std;

bool is_leap(int a){
	if(a%400==0) return true;
	else if(a%100==0) return false;
	else if(a%4==0) return true;
	else return false;

	return false;
}

// ==d067==
int main(){
	int y;
	while(cin >> y){
		cout << "a " << (is_leap(y)?"leap":"normal") << " year" << endl;
	}
}

// ==d069==
// int main(){
// 	int y;
// 	while(cin >> y){
// 		if(y==0) break;
// 		cout << "a " << (is_leap(y)?"leap":"normal") << " year" << endl;
// 	}
// }

// ==d070==
// int main(){
// 	int y, t;
// 	cin >> t;
// 	while(cin >> y){
// 		cout << "a " << (is_leap(y)?"leap":"normal") << " year" << endl;
// 	}
// }

// ==d071==
// int main(){
// 	int y;
// 	while(cin >> y){
// 		cout << "a " << (is_leap(y)?"leap":"normal") << " year" << endl;
// 	}
// }

// ==d072==
// int main(){
// 	int y, t;
// 	while(cin >> t){
// 		for(int i=0; i<t; i++){
// 			cin >> y;
// 			cout << "Case " << i+1 << ": a " << (is_leap(y)?"leap":"normal") << " year" << endl;
// 		}
// 	}
// }