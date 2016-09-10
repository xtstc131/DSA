#include "rpn.h"
float evaluate(char * S ,char*&RPN)
{
	Stack<char> optr; Stack<float> opnd;
	optr.push('\0');
	while (!optr.empty())
	{
		if(isdigit(*S)){
			//printf("%c\n", *S);
			readNumber(S, opnd);  append(RPN, opnd.top());
		}
		else
			switch (orderBetween(optr.top(),*S))
			{
			case'<':
				optr.push(*S);
				//printf("%c\n", *S);
				S++; break;
			case'=':
				optr.pop(); S++; break;
			case'>':
			{	char op = optr.pop(); 
				//printf("%c/n", op);
				append(RPN, op);
				if (op == '!') { auto pOpnd = opnd.pop(); opnd.push(calc(op, pOpnd)); }
				else
			{
				auto pOpnd2 = opnd.pop(); auto pOpnd1 = opnd.pop();
				opnd.push(calc(pOpnd1, op, pOpnd2));
			}
				break; 
			}
			default:exit(-1);//遇到语法错误不处理直接退出
			}	
	
	}
	return opnd.pop();
}
