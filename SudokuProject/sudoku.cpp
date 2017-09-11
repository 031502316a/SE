// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sudokulib.h"
using namespace std;

int main(int argc, char *argv[]) {
	freopen("sudoku.exe", "w", stdout);
	//sudoku.iosout.open("sudoku.txt");
	if (strcmp(argv[1], "-c") != 0 || argc!=3) {
		printf("error mate");
	}
	else {
		char* str = argv[2];
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] < '0' || str[i] > '9') {
				printf("error mate");
				return 0;
			}
		}
		int res = 0, tmp = 1;
		for (int i = len - 1; i >= 0; i--) {
			res += (str[i] - '0')*tmp;
			tmp *= 10;
		}
        sudokulib sudoku(res);
	    sudoku.dfs(0, 1);
	    sudoku.iosout.close();
	    return 0;
	}
	
}
