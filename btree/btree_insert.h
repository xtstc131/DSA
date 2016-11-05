#pragma once
template <typename T>
bool BTree<T>::insert(const T& e)
{
	BTNodePosi(T) v = search(e);
	if (v) return false;
	Rank r = _hot->key.search(e);
	_hot->key.insert(r + 1, e); //将新关键码插至对应的位置
	_hot->child.insert(r + 2, nullptr); //创建一个空子树指针
	_size++;
	solveOverflow(_hot);
	return true;
}