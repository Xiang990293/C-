#include<iostream>
using namespace std;

int main(){
    cout << "本系統將會要求使用者你輸入以一百個為單位的0~9的數字，請不要依照規律填寫，想到甚麼寫什麼，每個數字都要以空格隔開，知道請按1，並空格，若否則退出程式。" << endl;
    cout << "是否繼續？(1=yes/0=no)" << endl;
    int start=0;
    cin >> start;
    if(start!=1) return 0;
    int counter[10]={0};
    int a;
    int cycle_counter=0;
    while(start==1){
        cycle_counter++;
        for(int i=0; i<100; i++){
            cin >> a;
            counter[a]++;
        }

        cout << "是否繼續？(1=yes/0=no)" << endl;
        start=0;
        cin >> start;
    }

    int sum=0;
    for(int i=0; i<10; i++){
        cout << i << ": " << counter[i] << ", " << (float)counter[i]/(float)cycle_counter << "%" << endl;
        sum += counter[i];
    }

}