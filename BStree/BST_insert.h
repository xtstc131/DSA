#pragma once 
template <typename T>
BinNode<T>* BST<T>::insert(const T& e)
{
	BinNodePosi(T) & x = search(e);
	if (x) return x;
	x = new BinNode<T>(e, _hot);
	++  BinTree<T>::_size;
	BinTree<T>::updateHeight(x);
	return x;
}

