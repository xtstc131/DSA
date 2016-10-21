#include <iostream>
#include "bintree.h"
using namespace std;
int main()
{
	BinTree<char> a, b, c, x, y, z;
	y.makeTree('E', a, b);
	z.makeTree('F', a, b);
	x.makeTree('C', y, z);
	y.makeTree('D', a, b);
	z.makeTree('B', y, x);
	z.bintreeTest();
	z.levelTrav();
	z.preTrav();
	z.mirror();
	z.preTrav();
	BinTree<char> t = z;
	t.preTrav();
	getchar();
}