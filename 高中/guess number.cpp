#include <iostream>
#include <random>
using namespace std;

//目前尚未完成，設定中的次數限制和時間限制還需設計
//mode setting
//guesstimeslimit guesslimit

double r;
int g(int,int);

int main()
{
  int mainmenu,valuerangemax,valuerangemin;//初始化
  int mode,times,end,round;
  int useranswer,win;
  int guessnumber;
  bool guesslimitset,guesstimelimitset,endcheck;
  string settingselect;
  mode = -1; 
  win = 0;
  end = 0;
  round = 0;//初始化
  cout << "歡迎進入猜數字應用程式" << endl;
  cout << "1=遊戲開始，2=設定，3=模式選擇" << endl;//mainmenu
  cout << "請選擇:" << endl;
  cin >> mainmenu;
  while (win == 0)//結束條件 
  {
    if (mainmenu == 1)//遊戲開始
    {
      if (mode == -1)//模式-1
      {
        cout << "請輸入範圍最小值：" << endl;
        cin >> valuerangemin;
        cout << "請輸入範圍最大值：" << endl;
        cin >> valuerangemax;
        guessnumber = g(valuerangemin,valuerangemax);
        cout << "請開始猜，範圍由" << valuerangemin << "~" << valuerangemax << endl;
        cin >> useranswer;
        while (win == 0)//玩家猜測直到答對
        {
          if (useranswer > guessnumber)//猜太大
          {
            valuerangemax = useranswer;
            cout << "太大，請繼續，範圍" << valuerangemin << "~" << valuerangemax << endl;
            cin >> useranswer;
          }
          else if (useranswer < guessnumber)//猜太小
          {
            valuerangemin = useranswer;
            cout << "太小，請繼續，範圍" << valuerangemin << "~" << valuerangemax << endl;
            cin >> useranswer;
          }
          else if (useranswer==guessnumber)//猜中
          {
            cout << "猜中了，恭喜！！" << endl;
            win = 1;
          }
          else//亂打
          {
          cout << "您所輸入的內容不符合需求" << endl;
          cout << "請再次輸入" << endl;
          cout << "範圍" << valuerangemin << "~" << valuerangemax << endl;
          cin >> useranswer;
          }
         round = round + 1;
        }
      } 
      else if (mode==0)//模式0
      {
        valuerangemax = 1;
        valuerangemin = 100;
        guessnumber = g(valuerangemin,valuerangemax);
        cout << "請開始猜，範圍由" << valuerangemin << "~" << valuerangemax << endl;
        cin >> useranswer;
        while (win == 0)//玩家猜測
        {
          if (useranswer > guessnumber)//猜太大
          {
            valuerangemax = useranswer;
            cout << "太大，請繼續，範圍" << valuerangemin << "~" << valuerangemax << endl;
            cin >> useranswer;
          }
          else if (useranswer < guessnumber)//猜太小
          {
            valuerangemin = useranswer;
            cout << "太小，請繼續，範圍" << valuerangemin << "~" << valuerangemax << endl;
            cin >> useranswer;
          }
          else if (useranswer == guessnumber)//猜中
          {
            cout << "猜中了，恭喜！！" << endl;
            win = 1;
          }
          else//亂打
          {
          cout << "您所輸入的內容不符合需求" << endl;
          cout << "請再次輸入" << endl;
          cout << "範圍" << valuerangemin << "~" << valuerangemax << endl;
          cin >> useranswer;
          }
        round = round + 1;
        }
      }
      else if (mode==1)
      {
        valuerangemax = 1;
        valuerangemin = 500;
        guessnumber = g(valuerangemin,valuerangemax);
        cout << "請開始猜，範圍由" << valuerangemin << "~" << valuerangemax << endl;
        cin >> useranswer;
        while (win == 0)//玩家猜測
        {
          if (useranswer > guessnumber)//猜太大
          {
            valuerangemax = useranswer;
            cout << "太大，請繼續，範圍" << valuerangemin << "~" << valuerangemax << endl;
            cin >> useranswer;
          }
          else if (useranswer < guessnumber)//猜太小
          {
            valuerangemin = useranswer;
            cout << "太小，請繼續，範圍" << valuerangemin << "~" << valuerangemax << endl;
            cin >> useranswer;
          }
          else if (useranswer == guessnumber)//猜中
          {
            cout << "猜中了，恭喜！！" << endl;
            win = 1;
          }
          else//亂打
          {
          cout << "您所輸入的內容不符合需求" << endl;
          cout << "請再次輸入" << endl;
          cout << "範圍" << valuerangemin << "~" << valuerangemax << endl;
          cin >> useranswer;
          }
        round = round + 1;
        }
      }
      else
      {
        cout << "error" << endl;
      }
    } 
    else if (mainmenu==2)//設定
    {
      cout << "您想要設定什麼？" << endl;
      cout << "guesslimit(猜測次數限制),guesstimelimit(猜測時間限制)" << endl;
      cout << "請選擇：" << endl;
      cin >> settingselect;
      while (settingselect!="")
      {
        if (settingselect=="guesslimit")
        {
          if (guesslimitset==true)
          {
            cout << "目前猜測次數限制為開啟狀態，請用true/false設定" << endl;
            cin >> guesslimitset;
            settingselect = "";
          }
          else
          {
            cout << "目前猜測次數限制為關閉狀態，請用true/false設定" << endl;
            cin >> guesslimitset;
            settingselect = "";
          }
        }
        else if (settingselect=="guesstimelimit")
        {
          if (guesstimelimitset==true)
          {
            cout << "您要開啟時間限制嗎？";
            cout << "請輸入您想要之秒數" << endl;
            cin >> times;
            settingselect = "";
          }
          else
          {
            
          }
        }
        else
        {
          cout << "error" << endl;
        }
      }
    } 
    else if (mainmenu==3)//模式選擇
    {
      cout << "當前模式為" << mode << "，預設為-1" << endl;
      cout << "-1=自訂模式，0=1~100,1=1~500，請更改為想要的模式" << endl;
      cin >> mode;
      cout << "模式以更改為" << mode << endl;
      cout << "請選擇主選單選項";
      cin >> mainmenu;
    }
    else
    {
      cout << "error" << endl;
    }
  }
  /*if (win == 1)
  {
    cout << "想要在一次嗎？true/false" << endl;
    cin >> endcheck;
    if (endcheck == true)
    {
      end = 1;
    }
    else
    {
      end = 0;
    }
  }*/ //目前未實裝(再玩一次)
  cout << "你用了" << round << " 輪猜出正確數字";//計算猜測次數
  
  return 0;
}

int g(int valuerangemin,int valuerangemax)//完成
{
  random_device rd;
  mt19937 generator( rd() );
  uniform_real_distribution<float> unif(valuerangemin, valuerangemax);
  r = unif(generator);
  
  return ceil(r);
}

