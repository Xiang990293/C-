#include<iostream>
using namespace std;

bool check_full(int **sudoku_board){
	for(int i=0; i<9; i++) {
		int sum = 0;
		for(int j=0; j<9; j++) {
			sum += sudoku_board[i][j];
		}
		if(sum != 511) return false;
	}
	return true;
}

int** sudoku_wave_function_collapse(int **sudoku_board, int row, int column, int number){
	if(check_full(sudoku_board)) return sudoku_board;
	;
}

int main(){
	int sudoku_board[9][9] = {
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111},
		{0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111,0b111111111}
	};
	int temp;
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) {
		cin >> temp;
		if(temp != 0) {
			sudoku_board[i][j] = 0b1 << (temp-1);

			for(int k=0; k<9; k++) {
				if(k != i) sudoku_board[k][j] -= sudoku_board[i][j];
				if(k != j) sudoku_board[i][k] -= sudoku_board[i][j];
			}

			int square_row = i/3;
			int square_column = j/3; 
			for(int k=square_row; k<square_row+9; k++){
				for(int l=square_column; l<square_column+9; l++){
					if(k != i && l != j) sudoku_board[k][l] -= sudoku_board[i][j];
				}
			}
		}
	}
}