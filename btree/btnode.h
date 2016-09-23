#pragma once
#include "../Vector/Vector.h"

#define BTNodePosi(T) BTNode<T>*

template <typename T>
struct BTNode
{
	BTNodePosi(T) parent;//���ڵ�
	Vector<T> key;//�ؼ�������;
	Vector<BTNodePosi(T)> child;//�����������䳤���ܱ�key�� 1��
//���캯����ע�⣺BTNodeֻ����Ϊ���ڵ㴴�������Ҵ�����ʱ������0���ؼ����1���սڵ㣩	
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