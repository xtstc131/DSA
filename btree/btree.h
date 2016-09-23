#pragma once
#include "btnode.h"//引入B树节点
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
	explicit BTree(int order = 3) :_size(0), _order(order) { _root = new BTNode<T>(); }//构造函数：默认为最低3阶
	~BTree(){
		if (_root)
		{
			//TODO:释放所有节点
		}
	}//析构函数：释放所有节点
	int order()const { return _order; }//阶次
	int size()const { return _size; }//规模
	BTNodePosi(T) &root() { return _root; }//树根
	bool empty()const { return !_root; }//判空
	BTNodePosi(T) search(const T & e);//查找
	bool insert(const T & e);//插入
	bool remove(const T & e);//删除

};
#include "btree_implementation.h"