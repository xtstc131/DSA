#include "rpn.h"
void readNumber(char *& p , Stack<float>& stk)
{
	stk.push(static_cast<float>(*p - '0'));
	//printf("5\n");
	while(isdigit(*(++p)))
	{
		stk.push(stk.pop() * 10 + (*p - '0'));
	}
	if ('.' != *p)	
		//printf("11");
		return;
	//printf("12");
	float fraction = 1;
	while (isdigit(*(++p)))
		stk.push(stk.pop() + (*p - '0')*(fraction /= 10));
	//printf("%f", stk.top());
}
