#include<iostream>
#include<math.h>
#include<string>
using namespace std;

const int MAXSIZE = 5000;

int transresult[MAXSIZE+1];
int itoa(int integer){
    int length=to_string(integer).length();
    transresult[MAXSIZE+1]={0};
    transresult[0]=(integer==0)?0:(abs(integer)/integer);
    for(int i=MAXSIZE; i>MAXSIZE-length; i--){
        int j=MAXSIZE-i;
        transresult[i]=stoi(to_string(integer).substr(length-j-1,length-j));
    }
    return 0;
}

//已經定義
long double power(long double a,int b){
    long double c=a;

    if(b>0){
        for(int i=0; i<b-1; i++){
            c *= a;
        }
        return c;
    }else if(b==0){
        return 1;
    }else{
        return 1/power(a,-1*b);
    }
}

//已經定義
long double absol(long double a){
    if(a<0){
        return a*-1.0;
    }else{
        return a;
    }
}

long double root(long double a, int n){
    long double transresult1 = a;
    long double transresult2 = transresult1-(power(transresult1,n)-a)/(n*power(transresult1,n-1));
    for(int i = 0; absol(transresult2-transresult1)>0.0001 || i<10; i++){
        //cout << transresult2 << endl;
        transresult1 = transresult2;
        transresult2 = transresult1-(power(transresult1,n)-a)/(n*power(transresult1,n-1));
    }
    return transresult2;
}

int getSize(int a[]){
	int j;
	for(j=1; a[j]==0; j++);
	return MAXSIZE+1-j;
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

int absoled[MAXSIZE+1];
int absol(int a[]){
    absoled[MAXSIZE+1] = {0};
	if(a[0]==0) return 0;
	else absoled[0] = 1;
	for(int i=1; i<MAXSIZE+1; i++) absoled[i] = a[i];

	return 0;
}

int add(int a[], int b[], char op){
	compare(a,b);
	int result[MAXSIZE+1] = {};
	result[0] = a[0] * b[0];
	for(int i=1; i<MAXSIZE+1; i++) result[i] = 0;
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
	for(int i=1; i<MAXSIZE+1; i++) result[i] = 0;
	return 0;
}

int power(int a[], int b, char op){
	int result[MAXSIZE+1] = {};
	for(int i=1; i<MAXSIZE+1; i++) result[i] = 0;
	return 0;
}

int Sum[MAXSIZE+1];
int operate(int a[], int b[], char op){
    int Sum[MAXSIZE+1] = {0};
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
			int Sum[5001]={0};
		}
		
		for(int i=1; i<MAXSIZE+1; i++){
			if(Sum[MAXSIZE+1-i] < 0){
				Sum[MAXSIZE-i] = Sum[MAXSIZE-i] - 1;
				Sum[MAXSIZE+1-i] = Sum[MAXSIZE+1-i] + 10;
			}
		}
		
	}else if(op == '*'){
        Sum[0] = a[0] * b[0];
        if(Sum[0]==0) return 0;
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

	return 0;
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
				for(int j=0; j<MAXSIZE+1; j++) Sum1[j] = Sum[j];
			}
			
		}else if(b==0){
			itoa(1);
			for(int j=1; j<MAXSIZE+1; j++) Sum1[j] = transresult[j];
		}
	}

	return 0;
}

int divid(int a[], int b[]){
	if(compare(a, b)==1){
		int ten[MAXSIZE+1]={};
		itoa(10);
		for(int i=0; i<MAXSIZE+1; i++){
			ten[i] = transresult[i];
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
		itoa(0);
		for(int i=0; i<MAXSIZE+1; i++){
			shan[i] = transresult[i];
		}
		
		int reinput2[MAXSIZE+1]={};
		
		int bei_shu[MAXSIZE+1]={};
		
		int d_bei_shu[MAXSIZE+1]={};
		
		int power_of_ten[MAXSIZE+1]={};
		
		int minus1[MAXSIZE+1]={};
		
		int minus2[MAXSIZE+1]={};
		
		int sizeMinus = getSize(a)-getSize(b);
		for(int i=0; i<sizeMinus+1; i++){
			
			itoa(10);
			operate(transresult, sizeMinus-i, '^');
			for(int k=0; k<MAXSIZE+1; k++) power_of_ten[k] = Sum1[k];
			
			for(int j=1; j<10;j++){
				
				itoa(j);
				operate(transresult, b, '*');
				for(int k=0; k<MAXSIZE+1; k++){
					bei_shu[k] = Sum[k];
				}
				
				itoa(j-1);
				operate(transresult, b, '*');
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
					
					itoa(j-1);
					operate(power_of_ten, transresult, '*');
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
					
					itoa(j);
					operate(power_of_ten, transresult, '*');
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
		itoa(1);
		for(int k=0; k<MAXSIZE+1; k++){
			Sum[k] = transresult[k];
		}
	}else if(compare(a, b)==-1){
		itoa(0);
		for(int k=0; k<MAXSIZE+1; k++){
			Sum[k] = transresult[k];
		}
	}

	return 0;
}

int mot_main(){
	while(true){
		int A1[MAXSIZE+1]={};
		int B1[MAXSIZE+1]={};
		A1[0]=1;
		B1[0]=1;

		//operating
        if(compare(A1, B1)==1){
            int ten[MAXSIZE+1]={};
            itoa(10);
            for(int i=0; i<MAXSIZE+1; i++) ten[i] = transresult[i];
            
            int bei_qu[MAXSIZE+1]={};
            for(int i=0; i<MAXSIZE+1; i++) bei_qu[i] = A1[i];
            //return after minus
            int reinput1[MAXSIZE+1]={};
            for(int i=0; i<MAXSIZE+1; i++) reinput1[i] = A1[i];
            
            int qu[MAXSIZE+1]={};
            for(int i=0; i<MAXSIZE+1; i++) qu[i] = B1[i];
            
            int shan[MAXSIZE+1]={};
            itoa(0);
            for(int i=0; i<MAXSIZE+1; i++) shan[i] = transresult[i];
            
            int reinput2[MAXSIZE+1]={};
            int bei_shu[MAXSIZE+1]={};
            int d_bei_shu[MAXSIZE+1]={};
            int power_of_ten[MAXSIZE+1]={};
            int minus1[MAXSIZE+1]={};
            int minus2[MAXSIZE+1]={};
            
            int sizeMinus = getSize(A1)-getSize(B1);
            for(int i=0; i<sizeMinus+1; i++){
                itoa(10);
                operate(transresult, sizeMinus-i, '^');
                for(int k=0; k<MAXSIZE+1; k++){
                    power_of_ten[k] = Sum1[k];
                }
                
                for(int j=1; j<10;j++){
                    itoa(j);
                    operate(transresult, B1, '*');
                    for(int k=0; k<MAXSIZE+1; k++) bei_shu[k] = Sum[k];
                    
                    itoa(j-1);
                    operate(transresult, B1, '*');
                    for(int k=0; k<MAXSIZE+1; k++) d_bei_shu[k] = Sum[k];
                    
                    operate(power_of_ten, bei_shu, '*');
                    for(int k=0; k<MAXSIZE+1; k++) minus1[k] = Sum[k];
                    
                    operate(power_of_ten, d_bei_shu, '*');
                    for(int k=0; k<MAXSIZE+1; k++) minus2[k] = Sum[k];
                    
                    if(compare(reinput1, minus1)==-1){
                        itoa(j-1);
                        operate(power_of_ten, transresult, '*');
                        for(int k=0; k<MAXSIZE+1; k++) reinput2[k] = Sum[k];
                        
                        operate(shan, reinput2, '+');
                        for(int k=0; k<MAXSIZE+1; k++) shan[k] = Sum[k];
                        
                        operate(reinput1, minus2, '-');
                        for(int k=0; k<MAXSIZE+1; k++) reinput1[k] = Sum[k];
                        break;
                    }else if(compare(reinput1, minus1)==0){
                        
                        itoa(j);
                        operate(power_of_ten, transresult, '*');
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
        }else if(compare(A1, B1)==0){
            cout << 1 << endl;
        }else if(compare(A1, B1)==-1){
            cout << 0 << endl;
        }
	}
}
/*tool kit

for(int i=0; i<MAXSIZE+1; i++){
	a[i] = b[i];
}


a[0] = 1; 
for(int i=1; i<MAXSIZE+1; i++){
	a[i] = 0;
}
*/
using namespace std;

bool is_perfect_square(int a){
    if(sqrt(a)==(int)sqrt(a)/1) return true;
    else return false;
    return 0;
}

int main(){
    itoa(3000);
    for(int i=0; i<MAXSIZE+1; i++) cout << transresult[i];

    // for(int i=100; i<2147483647; i++){
    //     if(is_perfect_square(i)){
    //         int hundrad = stoi(to_string(i).substr(0,to_string(i).length()-2));
    //         int ten = stoi(to_string(i).substr(0,to_string(i).length()-1));
    //         // cout <<is_perfect_square(ten)<<", "<<is_perfect_square(hundrad) << endl;
    //         if(is_perfect_square(ten)&&is_perfect_square(hundrad)) cout << i << endl;
    //     }
    // }
    // cout << "program ended" << endl;

    return 0;
}