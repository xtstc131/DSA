#pragma once
template <typename T>
bool AVL<T>::remove(const T& e)
{
	BinNodePosi(T) & x = BST<T>::search(e);
	if (!x) return false;
	removeAt(x, _hot);
	--BinTree<T>::_size;
	for (BinNodePosi(T) g = _hot; g; g = g->parent)
	{
		if (!AvlBalaanced(*g))
			g = FromParentTo(*g) = BST<T>::rotateAt(tallerChild(tallerChild(g)));
		updateHeight(*g);
	}
	return true;
}
