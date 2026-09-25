#include<iostream>
using namespace std;

int main(){
  int case_id = 1, n = 0;
  while (cin >> n) {
    if (n == 0) return 0;
    cout << "Case " << case_id++ << ": " << (n >> 1) << endl;
  }
}