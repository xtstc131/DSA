#pragma once



inline void propFormu::rpnLike(const char* cal_s,char *RPN	)
{
	Stack<char> optr; Stack<char> opnd;
	optr.push('/0');
	while (!optr.empty())
	{
		if(IsProp(*cal_s))
		{
			putInStack(cal_s, opnd); append(RPN, opnd.top());
		}
		else
			switch (orderBetween(optr.top(), *cal_s))
			{
			case'<':
				optr.push(*cal_s);
				//printf("%c\n", *S);
				cal_s++; break;
			case'=':
				optr.pop(); cal_s++; break;
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
}
