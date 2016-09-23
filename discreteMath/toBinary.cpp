#pragma once

#include "rpnDiscrete.h"
void toBinary(int m,int n, Vector<bool> & trueVal)
{
	auto bit = 0; 
	while (n > 0)
	{
		bit = n % 2;
		if (bit == 1)//如果余数是1就把对应的那位设置为true
			//注： 已经把真值Vector都初始化为false,所以余数为0不用赋值
			trueVal[m] = true;
		m--;//向前移动一位
		n /= 2;
	}

			//printf("\n");			
		
}