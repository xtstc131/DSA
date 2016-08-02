//Stack的应用
//进制转换
#include <iostream>
#include "stack.h"
using namespace std;
inline void convert(Stack<char>& S, __int64 n ,int base)
{
	static char dight[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while(n > 0)
	{
		S.push(dight[n%base]);//余数转化为相应的字符后入栈
		//等到需要显示的时候再逐一出栈，正好为所求的结果
	//	cout << dight[n % base]<<endl;  //测试用 a
		n /= base;
	}

}
