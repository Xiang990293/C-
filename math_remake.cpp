#include <iostream>
#include <math.h>
using namespace std;

const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798;

long double fact(long double a){
    long double x=1;
    long b=a;
    if(a-b==0){
        for(int i=1; i<=a; i++){
            x*=i;
        }
    }else{
        x=0;
    }

    return x;
}

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

long double absol(long double a){
    if(a<0){
        return a*-1.0;
    }else{
        return a;
    }
}

long double root(long double a, int n){
	if(a == 0) return 0;
    long double num1 = a;
    long double num2 = num1-(power(num1,n)-a)/(n*power(num1,n-1));
    for(int i = 0; absol(num2-num1)>0.0000000000000000001 || i<100000; i++){
        //cout << num2 << endl;
        if(num1 == 0){
        	cout << "undef" << endl;
        	return 0;
		}
        num1 = num2;
        num2 = num1-(power(num1,n)-a)/(n*power(num1,n-1));
    }
    return num2;
}

long double sin(long double num, bool isRad){
    if (isRad!=true){
        int deg_i = num;
        num -= deg_i;
        deg_i %= 360;
        num += deg_i;
        num*=(pi/180);
    }

    if(num > 0){
        for(;num>2*pi;){
            num-=2*pi;
        }
    }else if(num < 0){
        for(;num<-2*pi;){
            num+=2*pi;
        }
    }
    
    long double x = 0;
    long double odd = 0;

    for(int i=0; i<40; i++){
        
        odd = (2*i+1);
        
        if(i%2==0){
            x+=power(num,odd)/fact(odd);
        }else{
            x-=power(num,odd)/fact(odd);
        }
    }

    if(x > 0 && x < 1e-15){
        x = 0;
    }

    if(x < 0 && x > -1e-15){
        x = 0;
    }
    
    return x;
}

long double cos(long double num, bool isRad){
    if (isRad!=true){
        int deg_i = num;
        num -= deg_i;
        deg_i %= 360;
        num += deg_i;
        num*=(pi/180);
    }

    if(num > 0){
        for(;num>2*pi;){
            num-=2*pi;
        }
    }else if(num < 0){
        for(;num<-2*pi;){
            num+=2*pi;
        }
    }

    long double x = sin(num+pi/2,true);
    
    return x;
}

int main(){
	cout.precision(30);
    long double x,y;
    while(cin >> x){
    	cout << root(x, 2) << endl;
	}
//    while(cin>>x>>y){
//        cout << sin(x,y) << " " << cos(x,y) << " " << sin(x) << " " << cos(x) << endl;
//    }

    return 0;
}
