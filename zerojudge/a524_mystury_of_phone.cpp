#include <iostream>
#include <algorithm>
using namespace std;

bool isAllZero(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] != 0) return false;
    }

    return true;
}

void putter(string head, int* other_num, int size){
    if (isAllZero(other_num, size)) {
        cout << head << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        // cout << "1:" << head << endl;
        int* still_other_num = new int[size];
        for (int i = 0; i < size; i++) still_other_num[i] = other_num[i];
        if (other_num[i] == 0) continue;
        still_other_num[i] = 0;
        putter(head+(char)(other_num[i]+48), still_other_num, size);
    }

    return;
}

int main(){

    int n;
    while(cin >> n){
        int* nums = new int[n];
        for (int i = 1; i <= n; i++) {
            nums[i-1] = n - i + 1;
        }
        putter("", nums, n);
    }
}
