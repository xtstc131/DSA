#pragma once
#include "stack.h"
//������д��
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


//�׳Ʊ��˵Ĵ���
inline bool paren(const char exp[], int lo, int hi) { //���ʽ����ƥ���飬�ɼ����������
	Stack<char> S; //ʹ��ջ��¼�ѷ��ֵ���δƥ���������
	for (auto i = lo; i <= hi; i++) /* ��һ��鵱ǰ�ַ� */ /*DSA*/ {
		switch (exp[i]) { //������ֱ�ӽ�ջ������������ջ��ʧ�䣬����ʽ�ز�ƥ��
		case '(': case '[': case '{': S.push(exp[i]); break;
		case ')': if ((S.empty()) || ('(' != S.pop())) return false; break;
			//����ĵط�����ʹ���˻�����Ķ�·���ԡ��������ˣ�
			//�ڱȽ���ջ���������Ƿ��뵱ǰ������ƥ���ͬʱ�������������ƥ��͵���
			//��ƥ��ͷ���false���������㵯�� Ҳ����ν������ǲ�֪�����Ҹߵ�����ȥ
		case ']': if ((S.empty()) || ('[' != S.pop())) return false; break;
		case '}': if ((S.empty()) || ('{' != S.pop())) return false; break;
		default: break; //�������ַ�һ�ɺ���
						/*DSA*/
		} //displayProgress(exp, i, S);
	}
	return S.empty(); //�������ʽɨ�����ջ�����Բ����������ţ���ƥ�䣻����ջ�գ�ƥ��
}