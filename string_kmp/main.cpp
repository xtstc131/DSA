#include <iostream>
#include "kmp_next.h"
using namespace std;
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
	{
		return fib(n - 1) + fib(n - 2);
	}

}
int Catalan(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return Catalan(n - 1) *(4 * n - 6) / n;
}

int main()
{
	//char* s = "abcabcabbac";
	//int * N = Next_Improve(s);
	//int* N_1 = Next_1(s);
	//for (int i = 0; i < strlen(s) ; i++)
	//	cout << N[i]<<" ";
	//cout << endl;
	//for (int i = 0; i < strlen(s); i++)
	//	cout << N_1[i] << " ";
	cout << Catalan(6);
	getchar();

}
