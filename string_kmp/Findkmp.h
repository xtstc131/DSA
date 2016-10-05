#pragma once
#include "kmp_next.h"
inline int FindKmp(const char * P , char * Q)
{
	int i = 0 ,j = 0, m = strlen(P), n = strlen(Q);
	auto a = Next_Improve(Q);
	while(i < m )
	{
		if (j == -1 || P[i] == Q[j])
		{
			i++; j++;
		}
		else
		{
			j = a[j];
		}	
	}
	return (j == m) ? i - m : -1;
}
