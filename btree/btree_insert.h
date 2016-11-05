#pragma once
template <typename T>
bool BTree<T>::insert(const T& e)
{
	BTNodePosi(T) v = search(e);
	if (v) return false;
	Rank r = _hot->key.search(e);
	_hot->key.insert(r + 1, e); //���¹ؼ��������Ӧ��λ��
	_hot->child.insert(r + 2, nullptr); //����һ��������ָ��
	_size++;
	solveOverflow(_hot);
	return true;
}