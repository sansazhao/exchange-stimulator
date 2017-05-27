// 5.22 week14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;


int mg[20][20];
int mh[20][20];
const int n = 2;
int step;

void s_path(int r, int c) {
	step--;
	if (r == 1 && c == 1) 
		return;
	mg[r][c] = 2;
	if (mh[r + 1][c] == step) 
		s_path(r + 1, c);
	if (mh[r - 1][c] == step) 
		s_path(r - 1, c);
	if (mh[r][c + 1] == step) 
		s_path(r, c + 1);
	if (mh[r][c - 1] == step) 
		s_path(r, c - 1);
}

void path(int r, int c,int sum,int &row, int &col) {
	if (sum <= mh[r][c]) 
		mh[r][c] = sum; 
	else 
		return; 
	if (r == row && c == col) {
		step = sum;
		return;
	}
	++sum;
	if (mg[r + 1][c] == 0) 
		path(r + 1, c,sum, row, col);
	if (mg[r - 1][c] == 0) 
		path(r - 1, c, sum,row, col);
	if (mg[r][c + 1] == 0) 
		path(r, c + 1, sum,row, col);
	if (mg[r][c - 1] == 0) 
		path(r, c - 1, sum, row, col);
}

int main()
{
	ifstream migong;
	stringstream s;
	int row;
	int col;
	migong.open("mg4.txt");
	migong >> row>>col;
	for (int i = 1; i <= row; ++i) {
		for (int k = 1; k <= col; ++k) {
			int a;
			migong >> a;
			mg[i][k] = a;
			mh[i][k] = row*col;
		}
	}
	mh[1][1] = 0;
	path(1, 1, 0,row, col);
	s_path(row,col);
	mg[1][1] = 2;
	for (int i = 1; i < row + 1; ++i) {
		for (int k = 1; k < col + 1; ++k) {
			cout << mg[i][k] << "\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

