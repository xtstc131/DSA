#pragma once
#include"../BStree/BST.h"
#define tallerChild(x) ( \
   stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : ( /*���*/ \
   stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( /*�Ҹ�*/ \
   IsLChild( * (x) ) ? (x)->lc : (x)->rc /*�ȸߣ��븸��xͬ���ߣ�zIg-zIg��zAg-zAg������*/ \
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