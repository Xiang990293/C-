#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class rabbit{
public:
	int weight;
	int poison_level;
	rabbit(int w){
		weight = w;
		poison_level = 0; 
	}
	void set_weight(int w){
		weight = w;
		poison_level = 0;
	}
	void poisoning(int poison){
		weight -= poison_level * poison;
	}
	void eating(int carrot_type, int carrot){
		weight += carrot;
		if(carrot_type == 4) poison_level++;
	}
};

int main(){
	int dimension;
	int xyzw[5]={0,0,0,0,0}, poison, weight;
	int i,  j;
	stringstream s;
	string str, temp;
	rabbit tommy(weight);
	while(cin >> dimension){
		for(i = 0; i < dimension; i++){
			cin >> xyzw[1] >> xyzw[2] >> xyzw[3] >> xyzw[4] >> poison >> weight;
			xyzw[3] *= -1;
			xyzw[4] *= -1;
			tommy.set_weight(weight);
			cin.ignore();
			getline(cin, str);
			while(tommy.weight > 0 && str.length() != 0){
				tommy.poisoning(poison);
				if(tommy.weight <= 0) break;
				if(str=="\n") break;
				else{
					temp = str[0];
					tommy.eating(stoi(temp), xyzw[stoi(temp)]);
					if(str.length() != 1) str.replace(0,2,"");
					else break;
				}
			}
			weight = tommy.weight;
			if(weight <= 0) cout << "bye~Rabbit" << endl;
			else cout << weight << "g" << endl;
		}
	}
}