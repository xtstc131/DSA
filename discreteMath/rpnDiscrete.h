#pragma once
#include"../Stack/stack.h"
#include "../Vector/Vector.h"
#include<iostream>
#include <cstdlib>
#include<cctype>

#include "priority.h"
using namespace std;

bool isProp(char c);//�ж��ǲ������⣨�ų���������Լ����������
void pushProp(char p, Vector<bool> &trueVal, Stack<bool> &oppr);//���������ֵ���ѹ��ջ��

char orderBetween(char , char );//�ж����������֮�������˳��
Rank optr2rank(char op);//����������������Rank������������˳����в���

void toBinary(int m,int n,Vector<bool> & trueVal);//������0->2^n-1������ת��ΪС����ʽ����ѹ����ֵջ��
//���㺯��
bool calc(bool a, char op, bool b);//���������
bool calc( bool b);//��Ŀ���������ʵ���Ƿ�����

int judgeNum(char * S);//�жϱ��ʽ�ж��ٲ�һ��������
//��ʽ���ɺ���
void createDis(int n ,string &, Vector<bool> &);
void createCon(int ,string &, Vector<bool> &);
//��Ҫ����
//���ʽ������㺯��
bool evaluate(char * expr, Vector<bool> & trueValue);