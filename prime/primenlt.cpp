#include "primenlt.h"
#include"../BitMap/bitmap.h"
int primeNLT(int low, int n, char* file)
{
	bitmap B(file, n);//������λͼ��0��ʾ
	while (low < n) //��c��ʼ����λ��
		if (B.test(low)) low++; //���ԣ�����
		else return low; //�����׸����ֵ�����
		return low; //��û������������������n��ʵ���в�����˼򻯴���
}
//����file�ļ��еļ�¼����[low, n)��ȡ��С������