#include "primenlt.h"
#include"../BitMap/bitmap.h"
int primeNLT(int low, int n, char* file)
{
	bitmap B(file, n);//素数用位图的0表示
	while (low < n) //从c开始，逐位地
		if (B.test(low)) low++; //测试，即可
		else return low; //返回首个发现的素数
		return low; //若没有这样的素数，返回n（实用中不能如此简化处理）
}
//根据file文件中的记录，在[low, n)内取最小的素数