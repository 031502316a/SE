#include "stdafx.h"
#include "sudokulib.h"


sudokulib::sudokulib(int x)
{
	n = x;
	sudoku[0][0] = 8;
}


sudokulib::~sudokulib()
{
}


void  sudokulib::print() {
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			iosout << sudoku[i][j] << " ";
		}
		iosout << endl;
	}
	iosout << endl << endl;
}


bool  sudokulib::panduan(int x, int y, int num) {
	for (int i = 0; i<9; i++) {         //判断行，列 
		if (sudoku[x][i] == num) {
			return false;
		}
		if (sudoku[i][y] == num) {
			return false;
		}
	}

	for (int i = x / 3 * 3; i<x / 3 * 3 + 3; i++) {      //判断3*3的宫格 
		for (int j = y / 3 * 3; j<y / 3 * 3 + 3; j++) {
			if (sudoku[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}


bool sudokulib::dfs(int x, int y) {
	if (y == 9) {
		x++, y = 0;
	}

	if (x>8) {
		print();
		n--;
		if (n == 0) {
			exit(-1);
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (panduan(x, y, i)) {
			sudoku[x][y] = i;
			if (dfs(x, y + 1)) {
				return true;
			}
			else {                                              //回溯 
				sudoku[x][y] = 0;

			}
		}
	}
	return false;
}