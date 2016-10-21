#pragma once
#include <cstring>
#include <cstdio>

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
	explicit bitmap(int n = 8 ) { init(n); }
	bitmap(char * file , int n)
	{
		init(n);
		FILE *fp =fopen(file, "r"); 
		fread(M, sizeof(char), N, fp); fclose(fp);
	}
	~bitmap()
	{
		delete[] M;
		M = nullptr;
	}
	////��ʵ������һһ��Ӧ��ϵʱ����������˸�Ч��������λ��λ���㡣����ÿ���ֽ�ͨ������
	//	8�����أ���ͨ����λ���㣺
	//	k >> 3		����ȷ����Ӧ�ı���λ�����ֽڵ��ȣ�
	//	ͨ���߼�λ�����㣺
	//	k & 0x07    ����ȷ���ñ���λ�ڴ��ֽ��е�λ�ã�ͨ����λ������
	//	0x80 >> (k & 0x07)		���ɵõ��ñ���λ�ڴ��ֽ��ж�Ӧ����ֵ���루mask����
	void set(int k) { expand(k);        M[k >> 3] |= (0x80 >> (k & 0x07)); }
	void clear(int k) { expand(k);        M[k >> 3] &= ~(0x80 >> (k & 0x07)); }
	bool test(int k) { expand(k); return M[k >> 3] & (0x80 >> (k & 0x07)); }
	void expand(int k) { //�������ʵ�Bitmap[k]�ѳ��磬��������
		if (k < 8 * N) return; //���ڽ��ڣ���������
		auto oldN = N;
		auto oldM = M;
		init(2 * k); //���������ƣ��ӱ�����
		memcpy_s(M, N, oldM, oldN); delete[] oldM; //ԭ����ת�����¿ռ�
	}
};
