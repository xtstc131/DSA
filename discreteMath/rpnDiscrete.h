#pragma once
#include"../Stack/stack.h"
#include "../Vector/Vector.h"
#include <cstdlib>
bool evaluate(char * expr);
bool isProp(char c);
void pushProp(bool p,Stack<bool>);
char orderBetween(char , char );
void toBinary(int n,Vector<bool>);
bool calc(bool a, char op, bool b);
bool calc(char op, bool b);