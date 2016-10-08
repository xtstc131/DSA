#pragma once
#include"binnode.h"
template<typename T>
class BinTree
{
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T) x);//更新节点高度
	void updateHeightAbove(BinNodePosi(T) x); //更新节点X及其祖先的高度
public:
	BinTree(): _size(0),_root(nullptr){}
	~BinTree() { if (_size > 0) remove(_root); }
	int size() const { return _size; } //规模
	bool empty() const { return !_root; } //判空
	BinNodePosi(T) root() const { return _root; } //树根
	BinNodePosi(T) insertAsRoot(T const& e); //插入根节点
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //e作为x的左孩子（原无）插入
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //e作为x的右孩子（原无）插入
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* & t); //T作为x左子树接入
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* & t); //T作为x右子树接入
	int remove(BinNodePosi(T) x); //删除以位置x处节点为根的子树，返回该子树原先的规模
	BinTree<T>* secede(BinNodePosi(T) x); //将子树x从当前树中摘除，并将其转换为一棵独立子树
	template <typename VST> //操作器
	void travLevel(VST& visit) { if (_root) _root->travLevel(visit); } //层次遍历
	template <typename VST> //操作器
	void travPre(VST& visit) { if (_root) _root->travPre(visit); } //先序遍历
	template <typename VST> //操作器
	void travIn(VST& visit) { if (_root) _root->travIn(visit); } //中序遍历
	template <typename VST> //操作器
	void travPost(VST& visit) { if (_root) _root->travPost(visit); } //后序遍历
	bool operator< (BinTree<T> const& t) //比较器（其余自行补充）
	{
		return _root && t._root && lt(_root, t._root);
	}
	bool operator == (BinTree<T> const& t) //判等器
	{
		return _root && t._root && (_root == t._root);
	}
	/*DSA*/
	/*DSA*/void stretchToLPath() { stretchByZag(_root); } //借助zag旋转，转化为左向单链
	/*DSA*/void stretchToRPath() { stretchByZig(_root, _size); } //借助zig旋转，转化为右向单链


};
#include"bintree_implementation.h"