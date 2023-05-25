#include<iostream>
#include<string>
using namespace std;

int readint(){
	int a=0;
	char c='0';
	do{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return a;
}

unsigned int binposGen(string a, unsigned short start, unsigned short end){
	unsigned int bp = 0b0;
	for(int i=start; i<=end; i++){
		bp <<= 1;
		bp += (a[i]=='('&& a[i+1]==')');
	}
	
	return bp;	
}

string pairchanger(string head, string a, unsigned short start, unsigned short end, string endif){
	//if input a is in final state given by parenthesespairer(),
	//return directly to end all recrusion
	if(a==endif) return a;
	
	if(a.length()<=3) return a;
	
	//making binpos, position with binary storing
	unsigned int binpos = binposGen(a,start,end);
	
	//find 1 in binpos
	unsigned int btemp=0b0;
	for(int i=start; i<=end; i++){
		btemp = binpos >> end-i;
		if(btemp&&(binpos!=0)){
			int length = end-i+1;
			string replaced = a.replace(i,2,")(");
//			string front = a.substr(0,i);
//			printf("%s is the result\n",front.c_str());
//			string last = replaced.substr(i);
//			printf("%s is the result\n",last.c_str());
			printf("%s\n", (head + replaced).c_str());
			printf("%s\n", pairchanger("", replaced, i, end, endif).c_str());
		}
		binpos -= btemp << end-i;
	}
	
	return "";
}

void parenthesespairer(int n){
	if(n==0) return;
	if(n==1){
		printf("()\n");
		return;
	}
	if(n==2){
		printf("(())\n()()\n");
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
	printf("%s\n", a.c_str());
	
	///set final state be like
	string final="";
	for(int i=0; i<n; i++) final+="()";
	
	///start recursion
	printf("%s\n", pairchanger("", a, 1, 2*(n-1)-1, final).c_str()); 
	
	return;
}

int main(){
	int n=0;
	while(n = readint()) parenthesespairer(n);
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
