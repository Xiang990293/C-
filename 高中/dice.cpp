#include <iostream>
#include <random>
using namespace std;

int main()
{
    float s;
    double r;
    int i,c; //s=骰子面數 c=骰子顆數 r=隨機浮點數
    cout << "請輸入骰子面數，限整數" << endl;
    cin >> s;
    cout << "再輸入骰子個數" << endl;
    cin >> c;
    cout << "您所骰到的數字" << endl;
    for (i=0;i<c;i++){
      random_device rd;
      mt19937 generator( rd() );
      uniform_real_distribution<float> unif(1, s);
      r = unif(generator);
      cout << ceil(r) << endl;
    }
    return 0;
}
