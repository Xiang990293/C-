//the solution but using easiest way to do
//
// #include<iostream>
// #include<string>
// using namespace std;
//
// int main(){
// 	string input="0";
// 	string output="";
// 	while(cin >> input){
// 		if(stoi(input)==0) return 0;
// 		for(int i=1; i<stoi(input); i++){
// 			if(i%7!=0){
// 				if(i!=1) output += " "; 
// 				output += to_string(i);	    
// 			}
// 		}
// 		cout << output << endl;
// 		output="";
// 	}
// }
//
//under is a solution way faster then above
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int find_length_with_seven(int a){
	if(a<10) return 2*a;
	else if(a<100) return find_length_with_seven(9)+floor(log10(a)+2)*(a-9);
	else if(a<1000) return find_length_with_seven(99)+floor(log10(a)+2)*(a-99);
	else if(a<10000) return find_length_with_seven(999)+floor(log10(a)+2)*(a-999);
	else return -1;
}

int seven_length_finder(int a){
	if(a==1) return floor(log10(7*a))+2;
	else if(a>1) return seven_length_finder(a-1)+floor(log10(7*a))+2;
	else return 0;
}

int main(){
	int max=0;
	string input="0";
	string output="";
	while(cin >> input){
		if(stoi(input)==0) return 0;
		if(stoi(input)==1){
			cout << "" << endl;
		}else if(stoi(input)<=max){
			cout << output.substr(0,find_length_with_seven(stoi(input)-1)-seven_length_finder((stoi(input)-1)/7)-1) << endl;
		}else{
			for(int i=max; i<stoi(input); i++){
                if(i%7!=0){
                    if(i!=1) output += " "; 
                    output += to_string(i);
                }
			}
			cout << output << endl;
			max = stoi(input);
		}
	}
} 
