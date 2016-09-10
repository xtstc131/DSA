#pragma once
#include"rpnDiscrete.h"
bool evaluate(char * expr)
{
	 Stack<bool> oppr; Stack<char> optr ;
	 optr.push('/0');
	while (!optr.empty()) {
		if (isProp(*expr)) {
			pushProp(*expr,oppr);
		}
		else {
			switch (orderBetween(optr.top(),*expr)) {
			case'<':
				optr.push(*expr);expr++;
				break;
			case'>':
				optr.pop(); expr++;
				break;	
			case'=':
				auto op = optr.pop();
				if (op == '!') {
					auto prop = oppr.pop(); calc(op, prop);
				}
				else {
					auto pOpnd2 = oppr.pop(); auto pOpnd1 = oppr.pop();
					oppr.push(calc(pOpnd1, op, pOpnd2));
				}
				break;
			default:exit(-1);
			}
		}
	}
	 return oppr.pop();
}
