#include "rpnDiscrete.h"
bool evaluate(char * expr, Vector<bool> & trueValue)
{
	Stack<bool> oppr; Stack<char> optr;
	optr.push('\0');
	while (!optr.empty()) {
		if (isProp(*expr)) {
			//printf("%c", *expr);
			pushProp(*expr, trueValue, oppr);
			expr++;
		}
		else {
			switch (orderBetween(optr.top(), *expr)) {
			case'<':
				optr.push(*expr); expr++;
				break;
			case'=':
				optr.pop(); expr++;
				break;
			case'>':
				auto op = optr.pop();
				if (op == '!') {
					auto pOpnd = oppr.pop(); oppr.push(calc(pOpnd));
				}
				else {
					auto pOpnd2 = oppr.pop(); auto pOpnd1 = oppr.pop();
					oppr.push(calc(pOpnd1, op, pOpnd2));
				}
				break;
			}
		}
	}
	return oppr.pop();
}
