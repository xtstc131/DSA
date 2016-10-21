#pragma once
#include "kmp_next.h"
inline int FindKmp(const char * P , char * Q)
{
	int i = 0 ,j = 0, m = strlen(P), n = strlen(Q);
	auto a = Next_Improve(Q);
	while(i < m )
	{
		if (j == -1 || P[i] == Q[j])//两个判断的顺序不能变
		{
			i++; j++;
		}
		else//回溯
		{
			j = a[j];
		}	
	}
	delete[] a;//释放失败函数列表
	return (j == m) ? i - m : -1;
}
