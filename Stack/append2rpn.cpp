#include "rpn.h"
void append(char*& rpn, float opnd) { //������������RPNĩβ
	int n = strlen(rpn); //RPN��ǰ���ȣ���'\0'��β������n + 1��
	char buf[64];
	if (opnd != static_cast<float>(static_cast<int>(opnd))) sprintf(buf, "%.2f \0", opnd); //�����ʽ����
	else                          sprintf(buf, "%d \0", static_cast<int>(opnd)); //������ʽ
	rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + strlen(buf) + 1))); //��չ�ռ�
	strcat(rpn, buf); //RPN�ӳ�
}

void append(char*& rpn, char optr) { //�����������RPNĩβ
	int n = strlen(rpn); //RPN��ǰ���ȣ���'\0'��β������n + 1��
	rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + 3))); //��չ�ռ�
	sprintf(rpn + n, "%c ", optr); rpn[n + 2] = '\0'; //����ָ���������
}