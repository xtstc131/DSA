#pragma once
template <typename T>
BinNode<T>* AVL<T>::insert(const T& e)
{
	BinNodePosi(T)&x = BST<T>::search(e);
	if (x) return x;
	x = new BinNode<T>(e, _hot);
	++BinTree<T>::_size;
	for (BinNodePosi(T) g = BST<T>::_hot; g; g = g->parent)
	{
		if (!(AvlBalaanced(*g)))
		{
			FromParentTo(*g) = BST<T>::rotateAt(tallerChild(tallerChild(g)));
			break;
		}
		else
		{
			updateHeight(g);
		}
	}
	return x;
}