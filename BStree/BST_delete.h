#pragma once
template<typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T) & x , BinNodePosi(T) & hot)
{
	BinNodePosi(T) w = x;//ʵ�ʱ�ժ���ڵ�
	BinNodePosi(T) succ = nullptr;//ʵ�ʱ�ɾ�ڵ�Ľ����ߣ����壩
	if (!HasLChild(*x)) succ = x = x->rc;
	else if (!HasRChild(*x)) succ = x = x->lc;//��ʱsuccҲ���ǿյ�
	else
	{
		w = w->succ();
		x->data = w->data;
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;//�����ɾ���Ľڵ�ĸ���������X�ģ���ô��ɾ���Ľڵ���Һ���Ӧ�ý���
		//��λ�ó�ΪX���Һ��ӣ���֮����X�����Ϊ�丸�׵�����
	}
	hot = w->parent;
	if (succ) succ->parent = hot;//����ɾ���ڵ�ĺ����hot����
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
