#pragma once
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* t)
{
	if ((x->lc = t->_root)) x->lc->parent = x;
	_size += t->_size;
	updateHeightAbove(x);
	t->_root = nullptr;
	t->_size = 0;
	
	return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* t)
{
	if ((x->rc = t->_root)) x->rc->parent = x;
	_size += t->_size;
	updateHeightAbove(x);
	t->_root = nullptr;
	t->_size = 0;

	return x;
}
