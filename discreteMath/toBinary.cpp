#pragma once

#include "rpnDiscrete.h"
void toBinary(int m,int n, Vector<bool> & trueVal)
{
	auto bit = 0; 
	while (n > 0)
	{
		bit = n % 2;
		if (bit == 1)//���������1�ͰѶ�Ӧ����λ����Ϊtrue
			//ע�� �Ѿ�����ֵVector����ʼ��Ϊfalse,��������Ϊ0���ø�ֵ
			trueVal[m] = true;
		m--;//��ǰ�ƶ�һλ
		n /= 2;
	}

			//printf("\n");			
		
}