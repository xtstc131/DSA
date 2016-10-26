#pragma once
template<typename T>
static BinNodePosi(T) & searchIn(BinNodePosi(T) & v, const T & e, BinNodePosi(T) & hot)
{
	if (!v || e == v->data) return v;
	hot = v;
	return searchIn(e < v->data ? v->lc : v->rc, e, hot);
}

template<typename T>
BinNodePosi(T)& BST<T>::search(const T & e)
{
	return searchIn(BinTree<T>::_root, e, _hot = nullptr);
}