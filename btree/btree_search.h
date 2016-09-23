#pragma once
template <typename T>
BTNode<T>* BTree<T>::search(const T& e)
{
	BTNodePosi(T) v = _root; _hot = nullptr;
	while (v)
	{
		Rank r = v->key.search(e);
		if ((r >= 0) && (e == v->key[r]))
			return v;
		_hot = v; v = v->child[r + 1];
	}
	return nullptr;
}
