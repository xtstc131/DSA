//Stack��Ӧ��
//����ת��
#include <iostream>
#include "stack.h"
using namespace std;
inline void convert(Stack<char>& S, __int64 n ,int base)
{
	static char dight[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while(n > 0)
	{
		S.push(dight[n%base]);//����ת��Ϊ��Ӧ���ַ�����ջ
		//�ȵ���Ҫ��ʾ��ʱ������һ��ջ������Ϊ����Ľ��
	//	cout << dight[n % base]<<endl;  //������ a
		n /= base;
	}

}
