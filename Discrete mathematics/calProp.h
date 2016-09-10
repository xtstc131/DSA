#pragma once
#include "iostream"
#include "../Stack/stack.h"
using namespace std;
class propFormu
{
private:
	propFormu() = default; 
	void putInStack(const char * cal_s,Stack<char> opnd)
	{
		opnd.push(*cal_s);
		cal_s++;
	}
	static bool IsProp(char c);
public:
	void rpnLike(const char * cal_s,char * RPN);
};


#include "RpnLike_implement.h"
#include "isprop_implement.h"

