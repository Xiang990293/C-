#include <iostream>
using namespace std;
#pragma execution_character_set("utf-8")
//可以輸入中文惹~~~
 
int main()
{
  string username;
  float hightM;
  int weightKG,bmi;
  cout << "請告訴我您的名字" << endl;
  cin >> username;
  cout << "請輸入身高，單位為公尺" << endl; 
  cin >> hightM;
  cout << "請輸入體重，身高為公斤" << endl;
  cin >> weightKG;
  cout << "正在計算BMI..." << endl;
  bmi = weightKG / (hightM * hightM);
  cout << username <<"的BMI為" << bmi << endl;
  cout << "結果為:" << endl;
  if(bmi<18.5){
    cout << "過輕" << endl;
  }
  else if(bmi<24){
    cout << "正常" << endl;
  }
  else if(bmi<27){
    cout << "過重" << endl;
  }
  else if(bmi<30){
    cout << "輕度肥胖" << endl;
  }
  else if(bmi<35){
    cout << "中度肥胖" << endl;
  }
  else {
    cout << "重度肥胖" << endl;
  }
  
  return 0;
}
