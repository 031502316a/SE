
#pragma once
class sudokulib
{
private:
	int sudoku[9][9];
	int n;
public:
	ofstream iosout;
	sudokulib(int x);
	~sudokulib();
	void print();
	bool panduan(int x, int y, int num);
	bool dfs(int x, int y);

};

