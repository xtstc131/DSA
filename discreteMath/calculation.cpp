#include"rpnDiscrete.h"
bool calc(bool a, char op, bool b)
{
	switch (op)
	{
	case '&':return  a & b;
	case '|':return  a | b;
	case '-':return  !a | b;
	case '=':return  a ^ b;
	default:exit(-1);
	}
}
bool calc( bool b)
{
	return !b;
}