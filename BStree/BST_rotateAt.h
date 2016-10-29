#pragma once
template <typename T>
BinNode<T>* BST<T>::rotateAt(BinNode<T>* v)
{
	BinNodePosi(T) p = v->parent; BinNodePosi(T) g = p->parent;
	if(IsLChild(*p)) // Zig
	{
		if(IsLChild(*v)) // Zig-Zig(LL)
		{
		return	connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
		}
		else // Zig-Zag(LR)
		{
		return 	connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
		}
	}
	else // Zag
	{
		if(IsRChild(*v)) // Zag-Zag(RR)
		{
		return 	connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
		}
		else // Zag-Zig(RL)
		{
		return	connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
		}
	}
}
