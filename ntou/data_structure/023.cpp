#include<iostream>
using namespace std;

struct label{
	label(string name_i, int age_i, int stdid_i){
		name = name_i;
		age  = age_i;
		stdid = stdid_i;
	}

	string name;
	int age;
	int stdid;
};

int main(){
	label me("陳天裕",19,1020);
	label *ptr = &me;

	cout << "姓名：" << me.name << endl;
	cout << "年齡：" << (*ptr).age << endl;
	cout << "學號：" << ptr->stdid << endl;
}