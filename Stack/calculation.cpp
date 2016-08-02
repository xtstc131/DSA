#include "rpn.h"
float calc(float a,char op ,float b)
{
	switch(op)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	case'^':return pow(a, b);
	default:exit(-1);
	}
}
float calc(char op ,float b)
{
	switch (op)
	{
	case '!':return float(facI(int(b)));
	default:exit(-1);
	}
}