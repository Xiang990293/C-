#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct date{
	int year;
	int month;
	int day;
	date(){
		year = 0;
		month = 0;
		day = 0;
	}
	date(int y, int m, int d){
		year = y;
		month = m;
		day = d;
	}
	// bool operator==(date b){
	// 	return (((year == b.year) && (month == b.month)) && (day == b.day));
	// }
	string print(){
		return to_string(year)+"/"+to_string(month)+"/"+to_string(day);
	}
};

bool sort_date(date a, date b){
	if(a.year!=b.year) return a.year<b.year;
	else if(a.month!=b.month) return a.month<b.month;
	else return a.day>b.day;
}

bool is_leap(int a){
	if(a%400==0) return true;
	else if(a%100==0) return false;
	else if(a%4==0) return true;
	else return false;

	return false;
}

short is_big[12] = {1,-2,1,0,1,0,1,1,0,1,0,1};

int main(){
	int ans=0;
	int i=0;
	date dates[2];
	// int answer_counter = 0;
	while(cin >> dates[0].year >> dates[0].month >> dates[0].day >> dates[1].year >> dates[1].month >> dates[1].day){
		ans = 0;

		// answer_counter++;
		sort(dates, dates+2, &sort_date);
		// if(answer_counter==2292){
		// 	cout << dates[1].print() << endl;
		// }
		// cout << ans << endl;
		// cout << dates[0].print() << endl;
		// cout << dates[1].print() << endl;

		for(i=dates[0].year+1; i<dates[1].year; i++){
			ans+= 365 + is_leap(i);
		}
		//  cout << ans << endl;
		if(dates[0].year==dates[1].year)for(i=dates[0].month+1; i<dates[1].month; i++){
			ans+=30+is_big[i-1];
		}
		else{
			for(i=dates[0].month+1; i<=12; i++){
				ans+=30+is_big[i-1];
			}
			for(i=1; i<dates[1].month; i++){
				ans+=30+is_big[i-1];
			}
		}
		//  cout << ans << endl;
		if(dates[0].year==dates[1].year && dates[0].month==dates[1].month){
			ans+=dates[0].day - dates[1].day;
		}
		else{
			ans+= 30+is_big[dates[0].month-1]-dates[0].day + dates[1].day;
		}
		//  cout << ans << endl;
		if((dates[0].month==2&&dates[0].day<=28)||(dates[0].month==1)) ans+=is_leap(dates[0].year);
		//  cout << ans << endl;
		if(dates[1].month>2) ans+=is_leap(dates[1].year);

		ans += (is_leap(dates[0].year)&&((dates[0].month == 2) && (dates[0].day == 29)));

		cout << ans << endl;
	}

	return 0;
}
