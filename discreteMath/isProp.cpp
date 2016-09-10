#include "rpnDiscrete.h"
bool isProp(char c)
{
	c = toupper(c);
	return (c >= 80 && c <= 90) ? true : false;
}