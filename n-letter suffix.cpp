// n-letter suffix.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include<set>
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
	string word;
	map <string,int> suffix;//��׺-����
	map<int, string> re_suffix;//���ڰ�������top10
	map<string, int>::iterator it;
	map<int, string>::iterator re_it;
	set<string>wordlist;
	set<string>::reverse_iterator s;
	int length_of_word=0;
	while (getline(in, word)) {
		wordlist.insert(word);
		string each_suffix;
		int len = word.size();
		if (len > n_letter) {
			each_suffix = word.substr(len - n_letter , len - 1);
			//ÿ�����ʵĺ�n����ĸȡ��
			suffix[each_suffix]++;  //map�иú�׺������+1
		}
	}
	for (it = suffix.begin();it != suffix.end();it++){
		re_suffix[(*it).second] = (*it).first;	
	}
	int re_suffix_size = re_suffix.size();
	for (int i = re_suffix_size; i > 10; --i) {
		re_suffix.erase((*re_suffix.begin()).first);
	}
	for(int i = 1;i<=10;i++){
		re_it = re_suffix.begin();
		cout <<"the suffix:"<< (*re_it).second <<"   "<< "the number:" << (*re_it).first <<"\t"<<endl;
		re_suffix.erase((*re_it).first);
	}
	cout << "query suffix:";
	string q_suffix;
	cin >> q_suffix;
	int num_of_suffix=0;
	int size = wordlist.size();
	for (s=wordlist.rbegin(); s != wordlist.rend(); s++) {
		string w= *s;
		if (w.size() >= q_suffix.size() && w.rfind(q_suffix) == w.size()-q_suffix.size()) {
			num_of_suffix++;
			cout << w << endl;
		}
	}
	cout << "the number of words of this suffix:" << num_of_suffix;
	cin.get();cin.get();
    return 0;
}

