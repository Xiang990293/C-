#include<iostream>
#include<math.h>
using namespace std;

/*void print_all(int clockwise, int msize, int** result){
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
}*/

int main(){
	int total, msize;

	int clockwise;

	cin >> total;
	for(int i=0; i<total; i++){
		cin >> msize >> clockwise;

		int** result = new int*[msize];
		for (int i = 0; i<msize; i++){
            result[i] = new int[msize];
            for(int j=0; j<msize; j++){
                result[i][j] = 0;
            }
		} // print_all(clockwise, msize, result)
		//int result[msize][msize] = {};

		// center n^2
		if (msize % 2 == 0) result[msize/2][msize/2-1] = msize * msize;
		else result[msize/2][msize/2] = msize * msize;

		int row, column;
        row = column = (msize % 2 == 0) ? msize/2-1 : msize/2;
		// find the value of main diagonal
		result[row][column] = (msize % 2 == 0)? msize * msize - 3 : msize * msize;
		for(int i = (msize % 2 == 0) ? 3 : 2;i<msize;i+=2) {
            result[--row][--column] = result[row][column] - 4 * i;
		}
		row = column = (msize % 2 == 0) ? msize/2 : msize/2+1;
		for(int i = (msize % 2 == 0) ? 1 : 2;i<msize;i+=2) {
            result[row++][column++] = result[msize-row-1][msize-column-1] + 2 * i;
		}

		for(int i = 1;i < msize; i++){ // left/right triangle
            if (i<=msize/2) result[i][i-1] = result[i][i] - 1;
            else result[i-1][i] = result[i][i] - 1;
            for(int j = (i<msize/2) ? i+1 : i-1; (i<msize/2)? j < msize - i : j > msize - i - 1; (i<msize/2)?j++:j--){
                if (i<msize/2) result[j][i-1] = result[j-1][i-1] - 1;
                else result[j][i] = result[j+1][i] - 1;
            }
		}
		for(int i = 0;i < msize; i++){ // middle sand-clock
            for(int j = (i<msize/2)? i+1 : i-1; (i<msize/2)? (j < msize - i): (j > msize - i - 2); (i<msize/2)?j++:j--){
                if (i<msize/2) result[i][j] = result[i][j-1] + 1;
                else result[i][j] = result[i][j+1] + 1;
            }
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
