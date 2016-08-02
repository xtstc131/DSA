#pragma once
#pragma warning(disable:4996)
#include "stack.h"
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include"priority.h"
//#include <cctype>
inline __int64 facI(int n)
 { __int64 f = 1; while (n > 1) f *= n--; return f; } //½×³ËÔËËã£¨µü´ú°æ£©}
float calc(float a, char op, float b);
float calc(char op, float b);
void readNumber(char * &, Stack<float>&);
Operator optr2rank(char op);
char orderBetween(char, char);
void append(char*&, float);
void append(char*&, char);
float evaluate(char* expr, char*&rpn);