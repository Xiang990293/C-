#include<iostream>
using namespace std;

int main(){
	string str;
	while(cin >> str){
		int max = 1, counter = 1;
		char current = str[0];
		char current_max;
		str += '#';
		for(int i=1; i<str.length(); i++){
			if(str[i]!=current){
				current = str[i];
				counter = 1;
			}
			else{
				counter++;
				if(max < counter){
					max = counter;
					current_max = current;
				}
			}
		}

		cout << current_max << " " << max << endl; 
	}
}