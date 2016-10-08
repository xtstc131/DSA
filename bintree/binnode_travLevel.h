#pragma once
#include <queue>
using namespace std;

template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST& visit )
{
	queue<BinNodePosi(T)> Q;
	Q.push(this);
	while (!Q.empty())
	{
		BinNodePosi(T) x = Q.pop();
		visit(x->data);
		if (HasLChild(*x))
		{
			Q.push(x->lc);
		}
		if(HasRChild(*x))
		{
			Q.push(x->rc);
		}
	}
}
