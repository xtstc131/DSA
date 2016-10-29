#pragma once
template<typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T) & x , BinNodePosi(T) & hot)
{
	BinNodePosi(T) w = x;//实际被摘除节点
	BinNodePosi(T) succ = nullptr;//实际被删节点的接替者（广义）
	if (!HasLChild(*x)) succ = x = x->rc;
	else if (!HasRChild(*x)) succ = x = x->lc;//此时succ也不是空的
	else
	{
		w = w->succ();
		x->data = w->data;
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;//如果待删除的节点的父亲正好是X的，那么待删除的节点的右孩子应该接替
		//其位置成为X的右孩子，反之不是X，则成为其父亲的左孩子
	}
	hot = w->parent;
	if (succ) succ->parent = hot;//将被删除节点的后继与hot连接
	delete w;
	return succ;
}

template <typename T>
bool BST<T>::remove(const T& e)
{
	BinNodePosi(T) x = search(e);
	if (!x) return false;
	removeAt(x, _hot); --BinTree<T>::_size;
	BinTree<T>::updateHeight(_hot);
	return true;
}
