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
	
	int size() const { return _size; } //规模
	bool empty() const { return !_root; } //判空
	
	BinNodePosi(T) root() const { return _root; } //树根
	BinNodePosi(T) insertAsRoot(T const& e); //插入根节点
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //e作为x的左孩子（原无）插入
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //e作为x的右孩子（原无）插入
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*  t); //T作为x左子树接入
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*  t); //T作为x右子树接入
	BinTree<T>* secede(BinNodePosi(T) x)
	{
		FromParentTo(*x) = nullptr;
		updateHeightAbove(x->parent);
		BinTree<T> * S = new BinTree<T>;
		S->_root = x;		x->parent = nullptr;
		S->_size = x->size(); _size -= S->_size;
		return S;
	}//将子树x从当前树中摘除，并将其转换为一棵独立子树
							
//                    ------------DSA_Exp_2------------
//---------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////	
	//构造树
	void makeTree(const T & t ,BinTree<T> & l , BinTree<T> & r )
	{
		if (_root || (&l == &r)) return;
		_root = new BinNode<T>(t,nullptr,l._root,r._root);
		_size = l._size + r._size + 1;
		l._root = r._root = nullptr;
	}
	
	//删除树
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

	}//删除以位置x处节点为根的子树，返回该子树原先的规模

	//深度
	int Depth()
	{
		return depth(_root);
	}
	
	//总节点数量
	int NodeNumber()
	{
		return nodeNumber(_root);
	}
	
	//叶节点数量
	int LeafNumber()
	{
		return leafNumber(_root);
	}

	//测试实验代码：高度，叶节点，总节点个数
	void bintreeTest()
	{
		cout << "Depth: " << Depth() << endl;
		cout << "Size: " << NodeNumber() << endl;
		cout << "Leaf: " << LeafNumber() << endl;
	}
	
	//镜像操作
	void mirror()
	{
		mirror(_root);
	}
	//先序遍历
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

	//层序遍历
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
	
	template <typename VST> //操作器
	void travLevel(VST& visit) { if (_root) _root->travLevel(visit); } //层次遍历
	template <typename VST> //操作器
	void travpre(VST& visit) { if (_root) _root->travPre(visit); } //先序遍历
	template <typename VST> //操作器
	void travIn(VST& visit) { if (_root) _root->travIn(visit); } //中序遍历
	template <typename VST> //操作器
	void travPost(VST& visit) { if (_root) _root->travPost(visit); } //后序遍历
	
																	 //重载运算符
	bool operator > (BinTree<T> const& t) //比较器（其余自行补充）
	{
		return _root&& t._root && *_root > *(t->_root);
	}
	bool operator < (BinTree<T> const& t) //比较器（其余自行补充）
	{
		return _root&& t._root && *_root > *(t->_root);
	}
	bool operator <= (BinTree<T> const& t) //比较器（其余自行补充）
	{
		return _root && t._root &&*_root <= *(t->_root);
	}
	bool operator >=(BinTree<T> const& t) //比较器（其余自行补充）
	{
		return _root && t._root &&*_root >= *(t->_root);
	}
	bool operator == (BinTree<T> const& t) //判等器
	{
		return _root && t._root && (_root == t._root);
	}
	 
	/*DSA*/
	/*DSA*/void stretchToLPath() { stretchByZag(_root); } //借助zag旋转，转化为左向单链
	/*DSA*/void stretchToRPath() { stretchByZig(_root, _size); } //借助zig旋转，转化为右向单链
private:
	
	int height(BinNodePosi(T) x);
	//树的深度
	int depth(BinNodePosi(T) x);
	//节点数量
	int nodeNumber(BinNodePosi(T) x)
	{
		if (!x) return 0;
		return nodeNumber(x->lc) + nodeNumber(x->rc) + 1;
	}
	//叶子节点数
	int leafNumber(BinNodePosi(T) x)
	{
		if (!x) return 0;
		if (!HasBothChild(*x))
		{
			return 1;
		}
		return leafNumber(x->lc) + leafNumber(x->rc);
	}
	//镜像操作
	void mirror(BinNodePosi(T) x)
	{
		if (!x) return;
		mirror(x->lc);
		mirror(x->rc);
		BinNodePosi(T) temp = x->lc;
		x->lc = x->rc;
		x->rc = temp;
	}
	//拷贝操作
BinNodePosi(T)copy(const BinNodePosi(T) src)
{
	if (!src) return nullptr;
	BinNodePosi(T) p = new BinNode<T>(src->data);
	p->lc = copy(src->lc);
	p->rc = copy(src->rc);
	return p;//返回指针问题不大，但是要是返回的局部变量是一个数值变量或者一个对象那可能就会有小问题了哟
} 

};
#include"bintree_implementation.h"