#pragma once
int _depth = 0;
template <typename T>
int BinTree<T>::depth(BinNodePosi(T) x)
{
	if (!x) return 0;
	int ldepth = depth(x->lc) + 1;
	int rdepth = depth(x->rc) + 1;
	return ldepth > rdepth ? ldepth : rdepth;
}
