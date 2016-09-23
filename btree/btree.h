#pragma once
#include "btnode.h"//����B���ڵ�
template<typename T>
class BTree
{
protected:
	int _size;
	int _order;
	BTNodePosi(T) _root;
	BTNodePosi(T) _hot;
	void solveOverflow(BTNodePosi(T));
	void solveUnderflow(BTNodePosi(T));
public:
	explicit BTree(int order = 3) :_size(0), _order(order) { _root = new BTNode<T>(); }//���캯����Ĭ��Ϊ���3��
	~BTree(){
		if (_root)
		{
			//TODO:�ͷ����нڵ�
		}
	}//�����������ͷ����нڵ�
	int order()const { return _order; }//�״�
	int size()const { return _size; }//��ģ
	BTNodePosi(T) &root() { return _root; }//����
	bool empty()const { return !_root; }//�п�
	BTNodePosi(T) search(const T & e);//����
	bool insert(const T & e);//����
	bool remove(const T & e);//ɾ��

};
#include "btree_implementation.h"