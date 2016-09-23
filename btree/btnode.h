#pragma once
#include "../Vector/Vector.h"

#define BTNodePosi(T) BTNode<T>*

template <typename T>
struct BTNode
{
	BTNodePosi(T) parent;//父节点
	Vector<T> key;//关键码向量;
	Vector<BTNodePosi(T)> child;//孩子向量（其长度总比key多 1）
//构造函数（注意：BTNode只能作为根节点创建，而且创建的时候总有0个关键码和1个空节点）	
	BTNode() { parent = nullptr; child.insert(0, nullptr); }
	BTNode(T e , BTNodePosi(T) lc = nullptr , BTNodePosi(T) rc = nullptr)
	{
		parent = nullptr;
		key.insert(0, e);
		child.insert(0, lc); child.insert(1,rc);
		if (lc)
		{
			lc->parent = this;
		}
		if(rc)
		{
			rc->parent = this;
		}
	}
};