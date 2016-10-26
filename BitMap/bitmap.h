#pragma once
#pragma warning(disable : 4996 4800)
#include <cstring>
#include <cstdio>
#include<string>
using std::string;
class bitmap
{
private:
	char * M;
	int N;
protected:
	void init(int n)
	{
		M = new char[N = (n + 7) / 8];
		memset(M, 0, N);
	}
public:
	explicit bitmap(int n = 8) { init(n); }
	bitmap(char * file, int n)
	{
		init(n);
		FILE *fp = fopen(file, "r");
		fread(M, sizeof(char), N, fp); fclose(fp);
	}
	~bitmap()
	{
		delete[] M;
		M = nullptr;
	}
	////在实现上述一一对应关系时，这里借助了高效的整数移位和位运算。鉴于每个字节通常包含
	//	8个比特，故通过移位运算：
	//	k >> 3		即可确定对应的比特位所属字节的秩；
	//	通过逻辑位与运算：
	//	k & 0x07    即可确定该比特位在此字节中的位置；
	//	通过移位操作：
	//	0x80 >> (k & 0x07)		即可得到该比特位在此字节中对应的数值掩码（mask）。
	void set(int k) { expand(k);        M[k >> 3] |= (0x80 >> (k & 0x07)); }
	void clear(int k) { expand(k);        M[k >> 3] &= ~(0x80 >> (k & 0x07)); }
	bool test(int k) { expand(k); return M[k >> 3] & (0x80 >> (k & 0x07)); }
	int lengh() const
	{ return N ; }
	string  bit2string(int n)
	{
		expand(n - 1);
		string S;
		for (int i = 0; i < n; i++)
		{
			S += test(i) ? '1' : '0';
		}
		return S;
	}
	void expand(int k) { //若被访问的Bitmap[k]已出界，则需扩容
		if (k < 8 * N) return; //仍在界内，无需扩容
		auto oldN = N;
		auto oldM = M;
		init(2 * k); //与向量类似，加倍策略
		memcpy_s(M, N, oldM, oldN); delete[] oldM; //原数据转移至新空间
	}
	void print(int n) //逐位打印以检验位图内容，非必需接口
		/*DSA*/ {
		expand(n); for (int i = n - 1; i >= 0; i--) printf(test(i) ? "1" : "0");
	}
};
