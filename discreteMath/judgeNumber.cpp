#pragma once
#include "rpnDiscrete.h"
int judgeNum(char * S)
{
	auto num = -1;
	//printf("%c\n", *S);
	while ((*S) != '\0'){
		*S = toupper(*S);
		if (isProp(*S)) {
			if ((*S) - 80 > num) num = (*S) - 80;//��ΪP��ASCII����80�����Լ�80
			//printf("%d ", num);
		}
		S++;
	}
	return num ;
}


