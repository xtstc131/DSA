#pragma once
template <typename T>
BinNodePosi(T) BinNode<T>::zig()
{
	BinNodePosi(T) lChild = lc;
	lChild->parent = this->parent;
	if (lChild->parent)
	{
		(this == parent->lc ? parent->lc : parent->rc) = lChild;
	}
	lc = lChild->rc;
	if (lc)
	{
		lChild->rc->parent = this;
	}
	lChild->rc = this;
	this->parent = lChild;
	return lChild;
}

template <typename T>
BinNodePosi(T) BinNode<T>::zag()
{
	BinNodePosi(T) rChild = rc;
	rChild->parent = parent;
	if (rChild->parent)
	{
		(this == parent->lc ? parent->lc : parent->rc) = rChild;
	}
	rc = rChild->lc;
	if (rc)
	{
		rChild->lc->parent = this;
	}
	rChild->lc = this;
	this->parent = rChild;
	return rChild;
}
