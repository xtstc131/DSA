#pragma once
template <typename T>
BinNode<T> * BST<T>::connect34(BinNode<T>* a, BinNode<T>* b, BinNode<T>* c, BinNode<T>* T0, BinNode<T>* T1, BinNode<T>* T2, BinNode<T>* T3)
{
	a->lc = T0; if (T0) T0->parent = a;
	a->rc = T1; if (T1) T1->parent = a; BinTree<T>::updateHeight(a);
	c->lc = T2; if (T2) T2->parent = c;
	c->rc = T3; if (T3) T3->parent = c; BinTree<T>::updateHeight(c);
	b->lc = a;	a->parent = b;
	b->rc = c;  c->parent = b;

	BinTree<T>::updateHeight(b);
	return b;
 }
