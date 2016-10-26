#pragma once
#include"binnode.h"
template<typename T>
class BinTree
{
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T) x);//���½ڵ�߶�
	void updateHeightAbove(BinNodePosi(T) x); //���½ڵ�X�������ȵĸ߶�
public:
	//Contructor
	BinTree(): _size(0),_root(nullptr){}
	BinTree(BinTree<T> & t)
	{
		if (!(&t)) { _size = 0; _root = nullptr; }
		_size = t._size;
		_root = t.copy(t._root);
	}
	//Destructor
	virtual ~BinTree() { if (_size > 0) remove(_root); }
	
	int size() const { return _size; } //��ģ
	bool empty() const { return !_root; } //�п�
	
	BinNodePosi(T) root() const { return _root; } //����
	BinNodePosi(T) insertAsRoot(T const& e); //������ڵ�
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //e��Ϊx�����ӣ�ԭ�ޣ�����
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //e��Ϊx���Һ��ӣ�ԭ�ޣ�����
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*  t); //T��Ϊx����������
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*  t); //T��Ϊx����������
	BinTree<T>* secede(BinNodePosi(T) x)
	{
		FromParentTo(*x) = nullptr;
		updateHeightAbove(x->parent);
		BinTree<T> * S = new BinTree<T>;
		S->_root = x;		x->parent = nullptr;
		S->_size = x->size(); _size -= S->_size;
		return S;
	}//������x�ӵ�ǰ����ժ����������ת��Ϊһ�ö�������
							
//                    ------------DSA_Exp_2------------
//---------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////	
	//������
	void makeTree(const T & t ,BinTree<T> & l , BinTree<T> & r )
	{
		if (_root || (&l == &r)) return;
		_root = new BinNode<T>(t,nullptr,l._root,r._root);
		_size = l._size + r._size + 1;
		l._root = r._root = nullptr;
	}
	
	//ɾ����
	int remove(BinNodePosi(T) x)
	{	
		if (!x) return 0;
		else
		{
			int n = 1 +remove(x->lc) + remove(x->rc);
			delete x;
			x = nullptr;
			return n;
		}

	}//ɾ����λ��x���ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ

	//���
	int Depth()
	{
		return depth(_root);
	}
	
	//�ܽڵ�����
	int NodeNumber()
	{
		return nodeNumber(_root);
	}
	
	//Ҷ�ڵ�����
	int LeafNumber()
	{
		return leafNumber(_root);
	}

	//����ʵ����룺�߶ȣ�Ҷ�ڵ㣬�ܽڵ����
	void bintreeTest()
	{
		cout << "Depth: " << Depth() << endl;
		cout << "Size: " << NodeNumber() << endl;
		cout << "Leaf: " << LeafNumber() << endl;
	}
	
	//�������
	void mirror()
	{
		mirror(_root);
	}
	//�������
	void preTrav()
	{
		cout << "PreOrder Travel:\n";
		preTrav(_root);
		cout << endl;
	}
	void preTrav(BinNodePosi(T) x )
	{
		if (!x)
		{
			return;
		}
		cout << x->data<<" ";
		preTrav(x->lc);
		preTrav(x->rc);
	}
	void inTrav()
	{
		cout << "InOrder Travel:\n";
		inTrav(_root);
		cout << endl;
	}
	void inTrav(BinNodePosi(T) x)
	{
		if (!x)
		{
			return;
		}
		inTrav(x->lc);
		cout << x->data << " ";
		inTrav(x->rc);
	}

	//�������
	void levelTrav()
	{
		cout << "Level Travel:\n";
		levelTrav(_root);
		cout << endl;
	}
	void levelTrav(BinNodePosi(T) x)
	{
		queue<BinNodePosi(T)> q;
		q.push(x);
		while(!q.empty())
		{
			BinNodePosi(T) p = q.front();
			q.pop();
			cout << p->data << " ";
			if (HasLChild(*p))
				q.push(p->lc);
			if (HasRChild(*p))
				q.push(p->rc);
		}
	}
	
	////////////----------------------------------------------------------------//////////////
	///////////////////////////////////////////////////////////////////////////////////////// 
	
	template <typename VST> //������
	void travLevel(VST& visit) { if (_root) _root->travLevel(visit); } //��α���
	template <typename VST> //������
	void travpre(VST& visit) { if (_root) _root->travPre(visit); } //�������
	template <typename VST> //������
	void travIn(VST& visit) { if (_root) _root->travIn(visit); } //�������
	template <typename VST> //������
	void travPost(VST& visit) { if (_root) _root->travPost(visit); } //�������
	
																	 //���������
	bool operator > (BinTree<T> const& t) //�Ƚ������������в��䣩
	{
		return _root&& t._root && *_root > *(t->_root);
	}
	bool operator < (BinTree<T> const& t) //�Ƚ������������в��䣩
	{
		return _root&& t._root && *_root > *(t->_root);
	}
	bool operator <= (BinTree<T> const& t) //�Ƚ������������в��䣩
	{
		return _root && t._root &&*_root <= *(t->_root);
	}
	bool operator >=(BinTree<T> const& t) //�Ƚ������������в��䣩
	{
		return _root && t._root &&*_root >= *(t->_root);
	}
	bool operator == (BinTree<T> const& t) //�е���
	{
		return _root && t._root && (_root == t._root);
	}
	 
	/*DSA*/
	/*DSA*/void stretchToLPath() { stretchByZag(_root); } //����zag��ת��ת��Ϊ������
	/*DSA*/void stretchToRPath() { stretchByZig(_root, _size); } //����zig��ת��ת��Ϊ������
private:
	
	int height(BinNodePosi(T) x);
	//�������
	int depth(BinNodePosi(T) x);
	//�ڵ�����
	int nodeNumber(BinNodePosi(T) x)
	{
		if (!x) return 0;
		return nodeNumber(x->lc) + nodeNumber(x->rc) + 1;
	}
	//Ҷ�ӽڵ���
	int leafNumber(BinNodePosi(T) x)
	{
		if (!x) return 0;
		if (!HasBothChild(*x))
		{
			return 1;
		}
		return leafNumber(x->lc) + leafNumber(x->rc);
	}
	//�������
	void mirror(BinNodePosi(T) x)
	{
		if (!x) return;
		mirror(x->lc);
		mirror(x->rc);
		BinNodePosi(T) temp = x->lc;
		x->lc = x->rc;
		x->rc = temp;
	}
	//��������
BinNodePosi(T)copy(const BinNodePosi(T) src)
{
	if (!src) return nullptr;
	BinNodePosi(T) p = new BinNode<T>(src->data);
	p->lc = copy(src->lc);
	p->rc = copy(src->rc);
	return p;//����ָ�����ⲻ�󣬵���Ҫ�Ƿ��صľֲ�������һ����ֵ��������һ�������ǿ��ܾͻ���С������Ӵ
} 

};
#include"bintree_implementation.h"