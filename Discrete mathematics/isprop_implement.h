#pragma once
#include <cctype>
inline bool propFormu::IsProp(char c)
{
	c = toupper(c);
		if ( c >= 65 && c <= 90)
	{
			return true;
	}
		return false;
		
}
