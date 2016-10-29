#pragma once
#include"../BStree/BST.h"
#define tallerChild(x) ( \
   stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : ( /*左高*/ \
   stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( /*右高*/ \
   IsLChild( * (x) ) ? (x)->lc : (x)->rc /*等高：与父亲x同侧者（zIg-zIg或zAg-zAg）优先*/ \
   ) \
   ) \
)
template<typename T>
class AVL :public BST<T>
{
	BinNodePosi(T) insert(const T& e)override;
	bool remove(const T & e)override;

};
#include"avl_implementation.h"