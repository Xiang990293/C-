#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 500;
const int BITSIZE = 1024;
const long long pi = 3.14159265358979823846264353279502884197169399375105820974944592307816406286208998628034825342117067798L;


int getSize(int a[]){
	int j;
	for(j=1; a[j]==0; j++){}
	return MAXSIZE+1-j;
}

int coutArray(int final[]){
	
	if(final[0]==0){
		cout << 0 << endl;
		return 0;
	}
	
	int j;
	for(j=1; final[j]==0; j++){}
	int size=MAXSIZE+1-j;
	
	int ans[MAXSIZE+1]={};
	
	for(int i=0; i<size; i++){
		ans[i]=0;
	}
	
	for(int i=j; i<MAXSIZE+1; i++)
		ans[i-j] = final[i];
	
	if(final[0]==-1){
		cout << '-';
	}
	
	for(int i=0; i<size; i++)
		cout << ans[i];
	cout << endl;

	return 0;
}

int compare(int a[], int b[]){
	if(a[0]==b[0]){
		if(a[0]==0){
			return 0;
		}
		for(int i=1; i < MAXSIZE+1; i++){
			if(a[i] < b[i]){
				return -1;
			}else if(a[i] > b[i]){
				return 1;
			}else if(i == MAXSIZE && a[i] == b[i]){
				return 0;
			}
		}
	}else{
		if(a[0]>b[0]){
			return 1;
		}else{
			return -1;
		}
	}

	return -2;
}

int Num[MAXSIZE+1]={};
int NumtoArr(int a_n){
	string A_s = to_string(a_n);
	
	for(int i=1; i<MAXSIZE+1; i++)
		Num[i]=0;
	
	if(A_s[0]=='-'){
		Num[0]=-1;
	}else if(a_n == 0){
		Num[0]=0;
	}else{
		Num[0]=1;
	}
	
	for(int i=0; i<A_s.length(); i++)
		Num[MAXSIZE-i] = A_s[A_s.length()-1-i]-48;
	
	return 0;
}

int absed[MAXSIZE+1] = {};
int abs(int a[]){
	if(a[0]==0){
		absed[0] = 0;
		return 0;
	}else if(a[0]==-1){
		absed[0] = 1;
	}
	
	for(int i=1; i<MAXSIZE+1; i++){
		absed[i] = a[i];
	}

	return 0;
}

int add(int a[], int b[], char op){
	compare(a,b);
	int result[MAXSIZE+1] = {};
	result[0] = a[0] * b[0];
	for(int i=1; i<MAXSIZE+1; i++)
		result[i] = 0;
	
	return 0;
}

int minus(int a[], int b[], char op){
	int result[MAXSIZE+1] = {};
	result[0] = a[0] * b[0];
	for(int i=1; i<MAXSIZE+1; i++) result[i] = 0;

	return 0;
}

int multiply(int a[], int b[], char op){
	int result[MAXSIZE+1] = {};
	result[0] = a[0] * b[0];
	for(int i=1; i<MAXSIZE+1; i++)
		result[i] = 0;
	
	return 0;
}

int power(int a[], int b, char op){
	int result[MAXSIZE+1] = {};
	for(int i=1; i<MAXSIZE+1; i++)
		result[i] = 0;
	
	return 0;
}

int divid(int a[], int b[], char op);

int Sum[MAXSIZE+1] = {};
int operate(int a[], int b[], char op){
	Sum[0] = a[0] * b[0];
	for(int i=1; i<MAXSIZE+1; i++)
		Sum[i] = 0;
	if(op == '+'){
		if(a[0]==b[0]){
			Sum[0] = a[0];
		}else{
			Sum[0] = a[0] + b[0];
		}
		
		for(int i=1; i<MAXSIZE+1; i++){
			Sum[MAXSIZE+1-i] = Sum[MAXSIZE+1-i] + a[MAXSIZE+1-i] + b[MAXSIZE+1-i];
			if(Sum[MAXSIZE+1-i]/10 > 0){
				Sum[MAXSIZE-i] = Sum[MAXSIZE+1-i] / 10;
				Sum[MAXSIZE+1-i] = Sum[MAXSIZE+1-i] % 10;
			}
		}
	}else if(op == '-'){
		if(compare(a, b)==-1){//b>a
			for(int i=1; i<MAXSIZE+1; i++){
				Sum[MAXSIZE+1-i] = b[MAXSIZE+1-i] - a[MAXSIZE+1-i];
				if(i==MAXSIZE){
					Sum[0] = -1;
				}
			}
		}else if(compare(a, b)==1){//a>b
			Sum[0] = 1;
			for(int i=1; i<MAXSIZE+1; i++)
				Sum[MAXSIZE+1-i] = a[MAXSIZE+1-i] - b[MAXSIZE+1-i];
		}else if(compare(a, b)==0){//a=b
			Sum[0] = 0;
			for(int i=1; i<MAXSIZE+1; i++)
				Sum[i] = 0;
		}
		
		for(int i=1; i<MAXSIZE+1; i++){
			if(Sum[MAXSIZE+1-i] < 0){
				Sum[MAXSIZE-i] = Sum[MAXSIZE-i] - 1;
				Sum[MAXSIZE+1-i] = Sum[MAXSIZE+1-i] + 10;
			}
		}
		
	}else if(op == '*'){
		for(int i=1; i<MAXSIZE/2+1; i++){
			for(int j=1; j<MAXSIZE/2+1;j++){
				Sum[MAXSIZE+2-i-j] = Sum[MAXSIZE+2-i-j] + a[MAXSIZE+1-j] * b[MAXSIZE+1-i];
			}
		}
		
		for(int i=1; i<MAXSIZE+1; i++){
			if(Sum[MAXSIZE+1-i]/10 > 0){
				Sum[MAXSIZE-i] = Sum[MAXSIZE-i] + Sum[MAXSIZE+1-i] / 10;
				Sum[MAXSIZE+1-i] = Sum[MAXSIZE+1-i] % 10;
			}
		}
	}

	return {};
}

int Sum1[MAXSIZE+1];
int operate(int a[], int b, char op){
	
	for(int i=0; i<MAXSIZE+1; i++){
		Sum1[i] = a[i];
	}
	
	if(op == '^'){
		
		if(b>0){
			for(int i=0; i<b-1; i++){
				operate(a, Sum1, '*');
				for(int j=0; j<MAXSIZE+1; j++){
					Sum1[j] = Sum[j];
				}
			}
			
		}else if(b==0){
			NumtoArr(1);
			for(int j=1; j<MAXSIZE+1; j++){
				Sum1[j] = Num[j];
			}
		}
	}

	return 0;
}

int divid(int a[], int b[]){
	if(compare(a, b)==1){
		int ten[MAXSIZE+1]={};
		NumtoArr(10);
		for(int i=0; i<MAXSIZE+1; i++){
			ten[i] = Num[i];
		}
		
		int bei_qu[MAXSIZE+1]={};
		for(int i=0; i<MAXSIZE+1; i++){
			bei_qu[i] = a[i];
		}
		
		int reinput1[MAXSIZE+1]={};
		for(int i=0; i<MAXSIZE+1; i++){
			reinput1[i] = a[i];
		}
		
		int qu[MAXSIZE+1]={};
		for(int i=0; i<MAXSIZE+1; i++){
			qu[i] = b[i];
		}
		
		int shan[MAXSIZE+1]={};
		NumtoArr(0);
		for(int i=0; i<MAXSIZE+1; i++){
			shan[i] = Num[i];
		}
		
		int reinput2[MAXSIZE+1]={};
		
		int bei_shu[MAXSIZE+1]={};
		
		int d_bei_shu[MAXSIZE+1]={};
		
		int power_of_ten[MAXSIZE+1]={};
		
		int minus1[MAXSIZE+1]={};
		
		int minus2[MAXSIZE+1]={};
		
		int sizeMinus = getSize(a)-getSize(b);
		for(int i=0; i<sizeMinus+1; i++){
			
			NumtoArr(10);
			operate(Num, sizeMinus-i, '^');
			for(int k=0; k<MAXSIZE+1; k++){
				power_of_ten[k] = Sum1[k];
			}
			
			for(int j=1; j<10;j++){
				
				NumtoArr(j);
				operate(Num, b, '*');
				for(int k=0; k<MAXSIZE+1; k++){
					bei_shu[k] = Sum[k];
				}
				
				NumtoArr(j-1);
				operate(Num, b, '*');
				for(int k=0; k<MAXSIZE+1; k++){
					d_bei_shu[k] = Sum[k];
				}
				
				operate(power_of_ten, bei_shu, '*');
				for(int k=0; k<MAXSIZE+1; k++){
					minus1[k] = Sum[k];
				}
				
				operate(power_of_ten, d_bei_shu, '*');
				for(int k=0; k<MAXSIZE+1; k++){
					minus2[k] = Sum[k];
				}
				
				if(compare(reinput1, minus1)==-1){
					
					NumtoArr(j-1);
					operate(power_of_ten, Num, '*');
					for(int k=0; k<MAXSIZE+1; k++){
						reinput2[k] = Sum[k];
					}
					
					operate(shan, reinput2, '+');
					for(int k=0; k<MAXSIZE+1; k++){
						shan[k] = Sum[k];
					}
					
					operate(reinput1, minus2, '-');
					for(int k=0; k<MAXSIZE+1; k++){
						reinput1[k] = Sum[k];
					}
					break;
				}else if(compare(reinput1, minus1)==0){
					
					NumtoArr(j);
					operate(power_of_ten, Num, '*');
					for(int k=0; k<MAXSIZE+1; k++){
						reinput2[k] = Sum[k];
					}
					operate(shan, reinput2, '+');
					for(int k=0; k<MAXSIZE+1; k++){
						shan[k] = Sum[k];
					}
					
					operate(reinput1, minus1, '-');
					for(int k=0; k<MAXSIZE+1; k++){
						reinput1[k] = Sum[k];
					}
					break;
				}
			}
		}
	}else if(compare(a, b)==0){
		NumtoArr(1);
		for(int k=0; k<MAXSIZE+1; k++){
			Sum[k] = Num[k];
		}
	}else if(compare(a, b)==-1){
		NumtoArr(0);
		for(int k=0; k<MAXSIZE+1; k++){
			Sum[k] = Num[k];
		}
	}

	return 0;
}

string calculator(string A, string B, char op){
	bool AgreaterB = A.length() > B.length();
	stringstream a, b;
	char f, g;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	a << A;
	b << B;
	string result = "";
	bool carry = 0;
	int temp;

	switch(op){
		case '+':
			for(int i = 0; i < ((AgreaterB)? A.length() : B.length()); i++){
				a >> f;
				b >> g;
				if(a.fail()) f='0';
				else if(b.fail()) g='0';
				temp = (int(f) + int(g) - 96 + carry);
				carry = 0;
				if (temp >= 10) carry = 1;
				result += ((temp>=10)?char(temp-10 + 48):char(temp + 48));
			}
			if(carry) result += '1';
			break;
		case '-':
			for(int i = 0; i < ((AgreaterB)? A.length() : B.length()); i++){
				a >> f;
				b >> g;
				if(a.fail()) f='0';
				else if(b.fail()) g='0';
				temp = (int(f) - int(g) + (int(f) < int(g)) * 10 - carry);
				carry = (int(f) < int(g));
				result += ((temp==0)?"":""+char(temp + 48));
			}
			if(result == "") result = "0";
			break;
	}

	reverse(result.begin(), result.end());

	return result;
}

int main(){
	string A = "", B = "";
	char op=0;

	while(cin >> A >> op >> B){
		cout << calculator(A, B, op) << endl;
	}
}

// int main(){
// 	string A="";
// 	char op='0';
// 	string B="";

// 	while(cin >> A >> B){
// 		//string > number of binary
// 		for(int i=0; i<A.length(); i++) A1[BITSIZE-i] = A[A.length()-1-i]-48;
// 		for(int i=0; i<B.length(); i++) B1[MAXSIZE-i] = B[B.length()-1-i]-48;
// 		cout << a << " " << b << endl;
// 		bitset<BITSIZE> A_bit(a);
// 		cout << "terminated?" << endl;
// 		bitset<BITSIZE> B_bit(b);
// 		cout << A_bit << " " << B_bit << endl;
// 	}
	
// 	/*
// 	while(cin>>A>>op>>B){
		
// 		int A1[MAXSIZE+1]={};
// 		int B1[MAXSIZE+1]={};
// 		A1[0]=1;
// 		B1[0]=1;
		
// 		//operating
// 		if(op != '/'){
// 			operate(A1, B1, op);
// 			coutArray(Sum);
// 		}else{
// 			if(compare(A1, B1)==1){
// 				int ten[MAXSIZE+1]={};
// 				NumtoArr(10);
// 				for(int i=0; i<MAXSIZE+1; i++){
// 					ten[i] = Num[i];
// 				}
				
// 				int bei_qu[MAXSIZE+1]={};
// 				for(int i=0; i<MAXSIZE+1; i++){
// 					bei_qu[i] = A1[i];
// 				}
// 				//return after minus
// 				int reinput1[MAXSIZE+1]={};
// 				for(int i=0; i<MAXSIZE+1; i++){
// 					reinput1[i] = A1[i];
// 				}
				
// 				int qu[MAXSIZE+1]={};
// 				for(int i=0; i<MAXSIZE+1; i++){
// 					qu[i] = B1[i];
// 				}
				
// 				int shan[MAXSIZE+1]={};
// 				NumtoArr(0);
// 				for(int i=0; i<MAXSIZE+1; i++){
// 					shan[i] = Num[i];
// 				}
				
// 				int reinput2[MAXSIZE+1]={};
				
// 				int bei_shu[MAXSIZE+1]={};
				
// 				int d_bei_shu[MAXSIZE+1]={};
				
// 				int power_of_ten[MAXSIZE+1]={};
				
// 				int minus1[MAXSIZE+1]={};
				
// 				int minus2[MAXSIZE+1]={};
				
// 				int sizeMinus = getSize(A1)-getSize(B1);
// 				for(int i=0; i<sizeMinus+1; i++){
					
// 					NumtoArr(10);
// 					operate(Num, sizeMinus-i, '^');
// 					for(int k=0; k<MAXSIZE+1; k++){
// 						power_of_ten[k] = Sum1[k];
// 					}
					
// 					for(int j=1; j<10;j++){
// 						//
// 						NumtoArr(j);
// 						operate(Num, B1, '*');
// 						for(int k=0; k<MAXSIZE+1; k++){
// 							bei_shu[k] = Sum[k];
// 						}
						
// 						NumtoArr(j-1);
// 						operate(Num, B1, '*');
// 						for(int k=0; k<MAXSIZE+1; k++){
// 							d_bei_shu[k] = Sum[k];
// 						}
						
// 						operate(power_of_ten, bei_shu, '*');
// 						for(int k=0; k<MAXSIZE+1; k++){
// 							minus1[k] = Sum[k];
// 						}
						
// 						operate(power_of_ten, d_bei_shu, '*');
// 						for(int k=0; k<MAXSIZE+1; k++){
// 							minus2[k] = Sum[k];
// 						}
						
// 						if(compare(reinput1, minus1)==-1){
							
// 							NumtoArr(j-1);
// 							operate(power_of_ten, Num, '*');
// 							for(int k=0; k<MAXSIZE+1; k++){
// 								reinput2[k] = Sum[k];
// 							}
							
// 							operate(shan, reinput2, '+');
// 							for(int k=0; k<MAXSIZE+1; k++){
// 								shan[k] = Sum[k];
// 							}
							
// 							operate(reinput1, minus2, '-');
// 							for(int k=0; k<MAXSIZE+1; k++){
// 								reinput1[k] = Sum[k];
// 							}
// 							break;
// 						}else if(compare(reinput1, minus1)==0){
							
// 							NumtoArr(j);
// 							operate(power_of_ten, Num, '*');
// 							for(int k=0; k<MAXSIZE+1; k++){
// 								reinput2[k] = Sum[k];
// 							}
// 							operate(shan, reinput2, '+');
// 							for(int k=0; k<MAXSIZE+1; k++){
// 								shan[k] = Sum[k];
// 							}
							
// 							operate(reinput1, minus1, '-');
// 							for(int k=0; k<MAXSIZE+1; k++){
// 								reinput1[k] = Sum[k];
// 							}
// 							break;
// 						}
// 					}
// 				}
// 				coutArray(shan);
// 			}else if(compare(A1, B1)==0){
// 				cout << 1 << endl;
// 			}else if(compare(A1, B1)==-1){
// 				cout << 0 << endl;
// 			}
// 		}
// 	}*/
// }


/*tool kit

for(int i=0; i<MAXSIZE+1; i++){
	a[i] = b[i];
}


a[0] = 1; 
for(int i=1; i<MAXSIZE+1; i++){
	a[i] = 0;
}
*/
