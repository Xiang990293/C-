#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    while(cin>>x>>y){
        int h,m;
        h=x+2;
        m=y+30;
        if(m>=60) h++, m-=60;
        if(h>=24) h-=24;
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}
// others