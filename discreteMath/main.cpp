#pragma once
#include "rpnDiscrete.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
char lett[11] = { 'P','Q','R','S','T','U','V','W','X','Y','Z' };
int main()
{

	char s[50];
	printf("Please input your formula:\n");
	gets_s(s);
	//��ʱ��
	clock_t start, finish;
	start = clock();

	string disJunc;//��������ȡ��ʽ���ַ���
	string  conJunc;//��������ȡ��ʽ���ַ���
	//printf("%c", s[0]);
	auto num = judgeNum(s);//�����ж��ٸ���ͬ������
	auto _num = 2 << num;//����2^num�������ж����ֲ�ͬ����ֵ���
	//printf("%d", num);
	for (auto i = 0; i <= num; i++)	printf("%c ", lett[i]);
	printf("%s\n", s);
	for (auto i = 0; i < _num; i++)
	{
		auto realVal = Vector<bool>(_num, _num, false);
		toBinary(num, i, realVal);
		for (auto j = 0; j <= num; j++)realVal[j] ? printf("T ") : printf("F ");
		auto Result = evaluate(s, realVal);
		Result ? printf("T ") : printf("F ");
		Result ? createDis(num, disJunc, realVal) : createCon(num, conJunc, realVal);
		printf("\n");
	}

	disJunc = disJunc.substr(0, disJunc.length() - 2);
	conJunc = conJunc.substr(0, conJunc.length() - 2);

	cout << "Disjunction:" << "\n" << disJunc << endl;
	cout << "Conjunction:" << "\n" << conJunc;

	finish = clock();
	printf("����ʱ%.3lf��", (double(finish) - start) / 1000);
	getchar();
	return  0;
}