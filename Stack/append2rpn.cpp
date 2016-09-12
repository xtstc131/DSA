#include "rpn.h"
void append(char*& rpn, float opnd) { //将操作数接至RPN末尾
	//printf("append_opnd:%f\n", opnd);
	int n = int(strlen(rpn));
	//printf("%d", n);//RPN当前长度（以'\0'结尾，长度n + 1）
	char buf[64];
	//printf("append_opnd:%f", opnd);
	if (opnd != static_cast<float>(static_cast<int>(opnd))) { sprintf(buf, "%.2f \0", opnd); } //浮点格式，或
	else { printf("append_opnd:%f\n", opnd); sprintf(buf, "%d \0", static_cast<int>(opnd)); } //整数格式
		rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + strlen(buf) + 1))); //扩展空间
		//避免使用C风格的内存管理函数的最好方法就是，使用stl提供的容器，它们为我们准备好了一切
		strcat(rpn, buf); //RPN加长
	}

void append(char*& rpn, char optr) { //将运算符接至RPN末尾
	int n = int (strlen(rpn)); //RPN当前长度（以'\0'结尾，长度n + 1）
	rpn = static_cast<char*>(realloc(rpn, sizeof(char) * (n + 3))); //扩展空间
	sprintf(rpn + n, "%c ", optr); rpn[n + 2] = '\0'; //接入指定的运算符
}