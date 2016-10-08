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
	int q, k;//q:ģ���ַ����±ꣻk:���ǰ��׺����
	size_t m = strlen(P);
	int * N = new int[m];
	N[0] = 0;//ģ���ַ����ĵ�һ���ַ������ǰ��׺����Ϊ0
	for (q = 1, k = 0; q < m; ++q)//forѭ�����ӵڶ����ַ���ʼ�����μ���ÿһ���ַ���Ӧ��nextֵ
	{
		while (k > 0 && P[q] != P[k])//�ݹ�����P[0]������P[q]��������ͬ��ǰ��׺����k
			k = N[k - 1];          //�����û��ϵ������ķ��������whileѭ�������δ���ľ������ڣ�ȷʵ�������  
		if (P[q] == P[k])//�����ȣ���ô�����ͬǰ��׺���ȼ�1
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