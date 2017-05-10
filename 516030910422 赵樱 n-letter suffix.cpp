// n-letter suffix.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"stdio.h"
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream in;
	in.open("dictionary.txt");
	if (!in)cout << "can't open dictionary";
	cout << "the number of letters of suffix:";
	int n_letter;
	cin >> n_letter;
	map <string,int> suffix;//词缀-个数
	vector<string>wordlist;//all words in dictionary
	vector<pair<int, string>>vec;
	string word;
	while (getline(in, word)) {
		wordlist.push_back(word);
		int len = word.size();
		if (len >= n_letter) {
			++suffix[word.substr(len - n_letter)];  //map中该后缀单词数+1
		}
	}
	for (auto&p : suffix)
		vec.emplace_back(p.second, p.first);
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < 10; i++) {
		auto& p = vec[i];
		cout << p.second << '\t' << p.first << endl;
	}
	reverse(wordlist.begin(), wordlist.end());
	cout << "\nquery suffix:";
	string q_suffix;
	cin >> q_suffix;
	int num_of_suffix=0;
	int size = q_suffix.size();
	for(string w:wordlist){
		if (w.size() >= size && 
			w.rfind(q_suffix) == w.size()-size) {
			num_of_suffix++;
			printf("%s\n", w.c_str());
		}
	}
	cout << "the number of words of this suffix:" << num_of_suffix<<endl;
	cin.get();cin.get();
    return 0;
}

