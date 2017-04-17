// practice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;


int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	if (!in)cout << "can't open the file";
	string word;
	while (getline(in, word))
		out << word<<endl;

	in.close();
	out.close();
    return 0;
}

