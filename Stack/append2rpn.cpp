#include "rpn.h"
void append(char*& rpn, float opnd) { //������������RPNĩβ
	//printf("append_opnd:%f\n", opnd);
	int n = int(strlen(rpn));
	//printf("%d", n);//RPN��ǰ���ȣ���'\0'��β������n + 1��
	char buf[64];
	//printf("append_opnd:%f", opnd);
	if (opnd != static_cast<float>(static_cast<int>(opnd))) { sprintf(buf, "%.2f \0", opnd); } //�����ʽ����
	else { printf("append_opnd:%f\n", opnd); sprintf(buf, "%d \0", static_cast<int>(opnd)); } //������ʽ
		rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + strlen(buf) + 1))); //��չ�ռ�
		//����ʹ��C�����ڴ����������÷������ǣ�ʹ��stl�ṩ������������Ϊ����׼������һ��
		strcat(rpn, buf); //RPN�ӳ�
	}

void append(char*& rpn, char optr) { //�����������RPNĩβ
	int n = int (strlen(rpn)); //RPN��ǰ���ȣ���'\0'��β������n + 1��
	rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + 3))); //��չ�ռ�
	sprintf(rpn + n, "%c ", optr); rpn[n + 2] = '\0'; //����ָ���������
}