#include "stringTool.h"
#include <iostream>
#include<string>
int main()
{
	string str = "abcaacbffsdewaamn";
	vector<string> str_split;
	strTool::split(str, str_split,"aa");
	for(int i = 0 ;i< str_split.size(); ++i)
	{
		cout << str_split[i] << " ";
	}
	getchar();
}