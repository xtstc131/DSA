#pragma once

#include "rpnDiscrete.h"
char let[11] = { 'P','Q','R','S','T','U','V','W','X','Y','Z' };
void createDis(int n ,string & s, Vector<bool> &r)
{
	for (auto i = 0 ; i <= n ;i++){
		if (!i) s += "( ";
		if (!r[i]){
			s += "!";
		}
		s += let[i];
		if (i != n ){
			s += " & ";
		}
		else {
			s += " ) | ";
		}
	}

}
void createCon(int  n , string & s, Vector<bool> & r)
{
	for (auto i = 0; i <= n; i++) {
		if (!i) s += "( ";
		
		if (
			r[i]) {
			s += "!";
		}
		
		s += let[i];
		
		if (i != n) {
			s += " | ";
		}
		else {
			s += " ) & ";

		}
	}

}

