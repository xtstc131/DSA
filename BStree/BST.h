#pragma once
#include"../bintree/bintree.h"
template<typename T>
class BST :public BinTree<T>
{
protected:
	BinNodePosi(T) _hot;
	BinNodePosi(T) connect34(BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));//3 + 4 结构连接三个节点和四个子树
	BinNodePosi(T) rotateAt(BinNodePosi(T) x);
public:
	virtual BinNodePosi(T) & search(const T & e);//search
	virtual BinNodePosi(T) insert(const T & e);//insert
	virtual bool remove(const T & e);//delete

};
#include"BST_implemetation.h"