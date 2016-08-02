#include "rpn.h"
void append(char*& rpn, float opnd) { //将操作数接至RPN末尾
	int n = strlen(rpn); //RPN当前长度（以'\0'结尾，长度n + 1）
	char buf[64];
	if (opnd != static_cast<float>(static_cast<int>(opnd))) sprintf(buf, "%.2f \0", opnd); //浮点格式，或
	else                          sprintf(buf, "%d \0", static_cast<int>(opnd)); //整数格式
	rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + strlen(buf) + 1))); //扩展空间
	strcat(rpn, buf); //RPN加长
}

void append(char*& rpn, char optr) { //将运算符接至RPN末尾
	int n = strlen(rpn); //RPN当前长度（以'\0'结尾，长度n + 1）
	rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + 3))); //扩展空间
	sprintf(rpn + n, "%c ", optr); rpn[n + 2] = '\0'; //接入指定的运算符
}