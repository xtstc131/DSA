#pragma once
template <typename T>
BinNode<T>* AVL<T>::insert(const T& e)
{
	BinNodePosi(T)&x = BST<T>::search(e);
	if (x) return x;
	BinNodePosi(T) beforeInsertX = x;
	x = new BinNode<T>(e, BST<T>::_hot);
	++BinTree<T>::_size;
	for (; beforeInsertX; beforeInsertX = beforeInsertX->parent)
	{
		if (beforeInsertX->height == 1)
		{
			FromParentTo(*beforeInsertX) = BST<T>::rotateAt(tallerChild(tallerChild(g)));
			break;
		}
		else
		{
			updateHeight(g);
		}
	}
	return x;
}