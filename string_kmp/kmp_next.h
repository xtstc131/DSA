#include <cstring>

inline int * Next(char * P)
{
	size_t m = strlen(P), j = 0;
	int * N = new int[m];
	int t = N[0] = -1;
	while (j < m - 1)
	{
		if (0 > t || P[j] == P[t])
		{
			j++; t++;
			N[j] = t;
		}
		else
		{
			t = N[t];
		}
	}
	return N;

}
inline int * Next_1(char * P)
{
	int q, k;//q:模版字符串下标；k:最大前后缀长度
	size_t m = strlen(P);
	int * N = new int[m];
	N[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0
	for (q = 1, k = 0; q < m; ++q)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
	{
		while (k > 0 && P[q] != P[k])//递归的求出P[0]···P[q]的最大的相同的前后缀长度k
			k = N[k - 1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解  
		if (P[q] == P[k])//如果相等，那么最大相同前后缀长度加1
		{
			k++;
		}
		N[q] = k;
	}
	return  N;
}
inline int * Next_Improve(char * P)
{
	size_t m = strlen(P), j = 0;
	auto N = new int[m];
	auto t = N[0] = -1;
	while (j < m - 1)
	{
		if (0 > t || P[j] == P[t])
		{
			N[j] = (P[++j] != P[++t] ? t : N[t]);
		}
		else
		{
			t = N[t];
		}
	}
	return N;

}