#pragma once
#include"binnode.h"
template<typename T>
class BinTree
{
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual updateHeight(BinNodePosi(T) x);//���½ڵ�߶�
	void updateHeightAbove(BinNodePosi(T) x); //���½ڵ�X�������ȵĸ߶�
public:
	BinTree(): _size(0),_root(nullptr){}
	~BinTree() { if (_size > 0) remove(_root); }
	int size() const { return _size; } //��ģ
	bool empty() const { return !_root; } //�п�
	BinNodePosi(T) root() const { return _root; } //����
	BinNodePosi(T) insertAsRoot(T const& e); //������ڵ�
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //e��Ϊx�����ӣ�ԭ�ޣ�����
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //e��Ϊx���Һ��ӣ�ԭ�ޣ�����
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &T); //T��Ϊx����������
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &T); //T��Ϊx����������
	int remove(BinNodePosi(T) x); //ɾ����λ��x���ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ
	BinTree<T>* secede(BinNodePosi(T) x); //������x�ӵ�ǰ����ժ����������ת��Ϊһ�ö�������
	template <typename VST> //������
	void travLevel(VST& visit) { if (_root) _root->travLevel(visit); } //��α���
	template <typename VST> //������
	void travPre(VST& visit) { if (_root) _root->travPre(visit); } //�������
	template <typename VST> //������
	void travIn(VST& visit) { if (_root) _root->travIn(visit); } //�������
	template <typename VST> //������
	void travPost(VST& visit) { if (_root) _root->travPost(visit); } //�������
	bool operator< (BinTree<T> const& t) //�Ƚ������������в��䣩
	{
		return _root && t._root && lt(_root, t._root);
	}
	bool operator== (BinTree<T> const& t) //�е���
	{
		return _root && t._root && (_root == t._root);
	}
	/*DSA*/
	/*DSA*/void stretchToLPath() { stretchByZag(_root); } //����zag��ת��ת��Ϊ������
	/*DSA*/void stretchToRPath() { stretchByZig(_root, _size); } //����zig��ת��ת��Ϊ������


};