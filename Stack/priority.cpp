#include "rpn.h"


Operator optr2rank(char op)
{
	switch (op)
	{
		case'+':return ADD;//¼Ó
		case'-':return SUB;//¼õ
		case'*':return MUL;//³Ë
		case'/':return DIV;//³ı
		case'^':return POW;//³Ë·½
		case'!':return FAC;//½×³Ë
		case'(':return L_P;//×óÀ¨ºÅ
		case')':return R_P;//ÓÒÀ¨ºÅ
		case'\0':return EOE;//ÆğÊ¼·ûÓëÖÕÖ¹·û
		default:exit(-1);//Î´ÖªÔËËã·û
	}
}
char orderBetween(char op1,char op2)
{
	return pri[optr2rank(op1)][optr2rank(op2)];
}
