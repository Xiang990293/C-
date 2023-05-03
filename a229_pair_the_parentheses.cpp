#include<iostream>
#include<string>
using namespace std;

unsigned int binposGen(string a, unsigned short start, unsigned short end){
	unsigned int bp = 0b0;
	for(int i=start; i<=end; i++){
		bp <<= 1;
		bp += (a[i]=='('&& a[i+1]==')');
	}
	
	return bp;	
}

string pairchanger(string a, unsigned short start, unsigned short end, string endif){
	//if input a is in final state given by parenthesespairer(),
	//return directly to end all recrusion
	if(a==endif) return a;
	
	if(a.length()==3) return a;
	
	//making binpos, position with binary storing
	unsigned int binpos = binposGen(a,start,end);
	
	//find 1 in binpos
	unsigned int btemp=0b0;
	for(int i=start; i<=end; i++){
		btemp = binpos >> end-i;
		if(btemp&&(binpos!=0)){
			int length = end-start+1;
			//?
			cout << a.replace(i,2,")(") << endl;
			//?
			cout << a.substr(i) << pairchanger(a.substr(i)+a.replace(i,2,")(").substr(end-i), i, end, endif) << endl;
		}
		binpos -= btemp << i;
	}
	
	return "";
}

void parenthesespairer(int n){
	if(n==0) return;
	if(n==1){
		cout << "()" << endl;
		return;
	}
	if(n==2){
		cout << "(())\n()()" << endl;
		return;
	}
	if(n>13) return; //break for too large num
	
	//do in 3<=n<=13
	
	///set initial state as a
	string a="",b="";
	for(int i=0; i<n; i++){
		a+="(";
		b+=")";
	}
	a+=b;
	cout << a << endl;
	
	///set final state be like
	string final="";
	for(int i=0; i<n; i++) final+="()";
	
	///start recursion
	pairchanger(a,1,2*(n-1)-1,final); 
	
	return;
}

int main(){
	int n=0;
	while(cin>>n) parenthesespairer(n);
}

/*
algorithm looks like:
n=1 //final state ()
()

n=2 //if find "()", replace with ")("
(())
	()()

n=3
((()))
	(()())
		(())()
		()(())
			()()()
			
n=4
(((())))
	((()()))
		((())())
			((()))()
	(()(()))
		(()()())
			(()())()
			(())(())
				(())()()
		()((()))
			()(()())
				()(())()
				()()(())
					()()()()

n=5
((((()))))
	(((()())))
		(((())()))
			(((()))())
				(((())))()
		((()(())))
			((()()()))
				((()())())
					((()()))()
				((())(()))
					((())()())
						((())())()
						((()))(())
							((()))()()
			(()((())))
				(()(()()))
					(()(())())
						(()(()))()
					(()()(()))
						(()()()())
							(()()())()
							(()())(())
								(()())()()
						(())((()))
							(())(()())
								(())(())()
								(())()(())
									(())()()()
				()(((())))
					()((()()))
						()((())())
							()((()))()
						()(()(()))
							()(()()())
								()(()())()
								()(())(())
									()(())()()
							()()((()))
							()()(()())
								()()(())()
								()()()(())
									()()()()()
*/
