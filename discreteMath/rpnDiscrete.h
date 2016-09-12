#pragma once
#include"../Stack/stack.h"
#include "../Vector/Vector.h"
#include<iostream>
#include <cstdlib>
#include<cctype>
#include "priority.h"
using namespace std;

bool isProp(char c);//判断是不是命题（排除运算符号以及其他情况）
void pushProp(char p, Vector<bool> &trueVal, Stack<bool> &oppr);//把命题的真值情况压入栈中

char orderBetween(char , char );//判断两个运算符之间的优先顺序
Rank optr2rank(char op);//返回运算符所代表的Rank，用于在运算顺序表中查找

void toBinary(int m,int n,Vector<bool> & trueVal);//用来把0->2^n-1的整数转化为小项形式，并压入真值栈中
//运算函数
bool calc(bool a, char op, bool b);//其他运算符
bool calc( bool b);//单目运算符，其实就是非运算

int judgeNum(char * S);//判断表达式有多少不一样的命题
//范式生成函数
void createDis(int n ,string &, Vector<bool> &);
void createCon(int ,string &, Vector<bool> &);
//主要函数
//表达式结果计算函数
inline bool evaluate(char * expr, Vector<bool> & trueValue)
{
	Stack<bool> oppr; Stack<char> optr;
	optr.push('\0');
	while (!optr.empty()) {
		if (isProp(*expr)) {
			//printf("%c", *expr);
			pushProp(*expr, trueValue, oppr);
			expr++;
		}
		else {
			switch (orderBetween(optr.top(), *expr)) {
			case'<':
				optr.push(*expr); expr++;
				break;
			case'=':
				optr.pop(); expr++;
				break;
			case'>':
				auto op = optr.pop();
				if (op == '!') {
					auto pOpnd = oppr.pop(); oppr.push(calc(pOpnd));
				}
				else {
					auto pOpnd2 = oppr.pop(); auto pOpnd1 = oppr.pop();
					oppr.push(calc(pOpnd1, op, pOpnd2));
				}
				break;
			}
		}
	}
	return oppr.pop();
}


