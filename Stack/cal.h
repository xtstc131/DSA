//#pragma once
//#include"stack.h"
//#include <cctype>
//#define N_OPRTR 9
////计算符号优先顺序表

//inline void readnumber(char* s,  Stack<float>& opnd)
//{
//	if (isdigit(opnd.top()))
//	{
//		auto top = opnd.top();
//		opnd.push(*s+top * 10);
//	}
//	else 
//		opnd.push(*s);
//	s++;
//}
//
//inline char orderbetween(char top, char c)
//{
//	
//}
//
//inline float evaluate(char * S , char * RPN)
//{
//	Stack<char> optr; Stack<float> opnd;
//	optr.push('\0');
//	while (!optr.empty())
//	{
//		if(isdigit(*S))
//		{
//			readnumber(S, opnd);
//		}
//		else
//		{
//			switch (orderbetween(optr.top(),*S))
//			{
//			case'<':
//				optr.push(*S), S++; break;
//			case'=':
//				optr.pop(); S++; break;
//			case'>':
//				auto op = optr.pop();
//				if (op == '!')opnd.push(culc());
//				else
//				{
//					auto popnd2 = opnd.pop(); auto popnd1 = opnd.pop();
//					opnd.push(culc());
//				}
//				break;
//			}	
//		}
//	}
//	return opnd.top();
//}
