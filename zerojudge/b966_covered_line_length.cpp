#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct line{
	int start;
	int end;
	line(){
		start=0;
		end=0;
	}
	line(int a, int b){
		if(a < b){
			start = a;
			end = b;
		}else{
			start = b;
			end = a;
		}
	}
	int length(){
		return end - start;
	}
	bool Covering(line b){
		return ((b.start>=start&&b.start<end)||((b.end>start&&b.end<=end)))?true:false;
	}
	// line cover(line b){
	// 	if (!Covering(b)) return *this;
	// 	return line((b.start>start)?start:b.start, (b.end>end)?b.end:end);
	// }
	// line operator^(line b){
	// 	return line();
	// }
	int show(){
		cout << "(" << start << ", " << end << ")"<<endl;
		return 0;
	}
};

bool sorting_line(line const& a, line const& b){
	if (a.start != b.start) return a.start < b.start;
	return a.end < b.end;
}

int main(){
	int c;
	
	while(cin >> c){
		int a, b;
		line lines[c];
		for(int i=0; i<c; i++){
			cin >> a >> b;
			lines[i] = line(a, b);
		}

		sort(lines, lines+c, &sorting_line);
		
		stack<line> covered;
		covered.push(lines[0]);
		for(int i=1; i<c; i++){
			line a = lines[i];
			line b = covered.top();
			short compare = 0b0;
			if(a.Covering(b)) compare += 2;
			if(b.Covering(a)) compare += 1;

			switch(compare){
				case 0:
					covered.push(lines[i]);
					break;
				case 1:
					continue;
				case 2:
					covered.top().end = lines[i].start;
					covered.push(lines[i]);
					break;
				case 3:
					covered.top().end = lines[i].start;
					covered.push(lines[i]);
					break;
			}
		}

		int total = covered.size();
		int length = 0;
		for(int i=0; i<total; i++){
			length += covered.top().length();
			covered.pop();
		}

		cout << length << endl;
	}
}