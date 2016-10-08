#pragma once
inline int max(int x , int y)//取两数最大值内联函数
{
	return x >= y ? x : y;
}

template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
	return x->height = 1 + max(stature(x->rc), stature(x->lc));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
	while (x) {
		updateHeight(x);
		x = x->parent;
	}
}


