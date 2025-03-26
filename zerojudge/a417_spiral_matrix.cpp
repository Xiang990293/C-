#include<iostream>
#include<math.h>
using namespace std;
/*
void print_all(int clockwise, int msize, int** result){
    cout << endl;
    switch(clockwise){
            case 1:{
                for(int i=0; i<msize; i++) {
                    for(int j=0; j<msize; j++){
                        printf("%5d",(result[i][j]));
                    }
                    cout << endl;
                }
                break;
            }
            case 2:{
                for(int i=0; i<msize; i++) {
                    for(int j=0; j<msize; j++){
                        printf("%5d",(result[j][i]));
                    }
                    cout << endl;
                }
                break;
            }

		}

    return;
} // print_all(clockwise, msize, result)*/

int* rot_90(int* value) {
    // a + bi => b - ai
    int temp = value[0];
    value[0] = value[1];
    value[1] = temp;

    value[1] *= -1;

    return value;
}

int* move_current(int* current, int* dir){
    current[0] += dir[0];
    current[1] += dir[1];

    return current;
} // move_current(current, dir);

int main(){
	int total, msize;

	int clockwise;

	cin >> total;
	for(int i=0; i<total; i++){
		cin >> msize >> clockwise;

		int** result = new int*[msize];
		for (int i = 0; i<msize; i++){
            result[i] = new int[msize];
            for(int j = 0; j<msize; j++){
                result[i][j] = 0;
            }
		} // print_all(clockwise, msize, result)
		//int result[msize][msize] = {};

		int counter = 1;
		int* current = new int[2];
		current[0] = 0; current[1] = 0;

		int* dir = new int[2];
		dir[0] = 0; dir[1] = 1;

		for (;counter <= msize;counter++) {
            result[current[0]][current[1]] = counter;
            if (counter < msize) current = move_current(current, dir);
		}
		dir = rot_90(dir);
		for (int i = msize - 1; counter<= msize * msize; i--) {
            for (int j = 0; j < i; j++) {
                move_current(current, dir);
                result[current[0]][current[1]] = counter++;
            }
            dir = rot_90(dir);
            for (int j = 0; j < i; j++) {
                move_current(current, dir);
                result[current[0]][current[1]] = counter++;
            }
            dir = rot_90(dir);
		}

		switch(clockwise){
            case 1:{
                for(int i=0; i<msize; i++) {
                    for(int j=0; j<msize; j++){
                        printf("%5d",result[i][j]);
                    }
                    cout << endl;
                }
                break;
            }
            case 2:{
                for(int i=0; i<msize; i++) {
                    for(int j=0; j<msize; j++){
                        printf("%5d",result[j][i]);
                    }
                    cout << endl;
                }
                break;
            }

		}
	}

	return 0;
}

/*

    int msize;

    while(cin >> msize){
        for(int i=0; i<msize; i++){
            cout <<  << " ";
        }
        cout << endl;
    }

*/
