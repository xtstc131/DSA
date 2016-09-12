#pragma once

#include"rpnDiscrete.h"
void pushProp(char c,Vector<bool> &trueVal, Stack<bool> & oppr)
{
	c = toupper(c);
	oppr.push(trueVal[c-80]);
}