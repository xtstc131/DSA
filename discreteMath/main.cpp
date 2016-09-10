#pragma once
#include "rpnDiscrete.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char s[] = "P-((P-Q)&!(!Q|!P))";
	char let[11] = { 'P','Q','R','S','T','U','V','W','X','Y','Z' };
	string disJunc;//储存主析取范式的字符串
	string  conJunc;//储存主和取范式的字符串
	//printf("%c", s[0]);
	auto num = judgeNum(s);//储存有多少个不同的命题
	auto _num = 2 << num;//储存2^num，就是有多少种不同的真值情况
	//printf("%d", num);
	for (int i = 0; i <= num; i++)	printf("%c ", let[i]);
	printf("%s\n", s);
	for (auto i = 0 ; i < _num ; i++)
	{
		auto realVal = Vector<bool>(_num,_num,false);
	    toBinary(num,i,realVal);
		for (auto j = 0; j <= num; j++)realVal[j] ? printf("T ") : printf("F ");
		auto Result = evaluate(s, realVal);
		Result ? printf("T "): printf("F ");
		Result ? createDis(num,disJunc,realVal) : createCon(num,conJunc,realVal);
		printf("\n");
	}
	disJunc = disJunc.substr(0, disJunc.length() - 2);
	conJunc = conJunc.substr(0, conJunc.length() - 2);
	
	cout <<"Disjunction:"<<"\n"<<disJunc<<endl;
	cout <<"Conjunction:"<<"\n"<<conJunc;
	getchar();
	return  0;
}