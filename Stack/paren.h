#pragma once
#include "stack.h"
//这是我写的
//inline bool paren(const char exp[],int lo ,int hi )
//{
//	Stack<char> S;
//	for (auto i = lo ; i< hi ;i++)
//	{
//		if ('(' == exp[i] || '[' == exp[i] || '{' == exp[i])
//		{
//			S.push(exp[i]);
//		}
//		else if
//			(!S.empty() &&
//			(
//				(S.top() == '('&&exp[i] == ')') ||
//				(S.top() == '{'&&exp[i] == '}') ||
//				(S.top() == '['&&exp[i] == ']')
//				)
//				) S.pop();
//		else
//			return false;
//	}
//	return S.empty();
//}


//俗称别人的代码
inline bool paren(const char exp[], int lo, int hi) { //表达式括号匹配检查，可兼顾三种括号
	Stack<char> S; //使用栈记录已发现但尚未匹配的左括号
	for (auto i = lo; i <= hi; i++) /* 逐一检查当前字符 */ /*DSA*/ {
		switch (exp[i]) { //左括号直接进栈；右括号若与栈顶失配，则表达式必不匹配
		case '(': case '[': case '{': S.push(exp[i]); break;
		case ')': if ((S.empty()) || ('(' != S.pop())) return false; break;
			//精妙的地方在于使用了或运算的短路特性。。简单明了，
			//在比较了栈顶的括号是否与当前的括号匹配的同时，又做到了如果匹配就弹出
			//不匹配就返回false，这样就算弹出 也无所谓，真的是不知道比我高到哪里去
		case ']': if ((S.empty()) || ('[' != S.pop())) return false; break;
		case '}': if ((S.empty()) || ('{' != S.pop())) return false; break;
		default: break; //非括号字符一律忽略
						/*DSA*/
		} //displayProgress(exp, i, S);
	}
	return S.empty(); //整个表达式扫描过后，栈中若仍残留（左）括号，则不匹配；否则（栈空）匹配
}