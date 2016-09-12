#pragma once

#include "rpnDiscrete.h"

Rank optr2rank(char op)
{
	switch (op) {
		case'&': return 0;
		case'|': return 1;
		case'-': return 2;
		case'=': return 3;
		case'!': return 4;
		case'(': return 5;
		case')': return 6;
		case'\0':return 7;
		default:exit(-1);
	}
}

char orderBetween(char op1, char op2)
{
	return pri[optr2rank(op1)][optr2rank(op2)];
}