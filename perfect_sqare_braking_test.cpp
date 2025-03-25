#include<iostream>
#include<math.h>
#include<string>
using namespace std;

bool is_perfect_square(int a){
    if(sqrt(a)==(int)sqrt(a)/1) return true;
    else return false;
    return 0;
}

int main(){

    for(int i=100; i<2147483647; i++){
        if(is_perfect_square(i)){
            int hundrad = stoi(to_string(i).substr(0,to_string(i).length()-2));
            int ten = stoi(to_string(i).substr(0,to_string(i).length()-1));
            // cout <<is_perfect_square(ten)<<", "<<is_perfect_square(hundrad) << endl;
            if(is_perfect_square(ten)&&is_perfect_square(hundrad)) cout << i << endl;
        }
    }
    cout << "program ended" << endl;

    return 0;
}