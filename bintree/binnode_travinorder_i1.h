#pragma once
template<typename T>
static void goAlongLeftBranch(BinNodePosi(T) x ,Stack<BinNodePosi(T)> & S  )
{
	while (x)
	{
		S.push(x);
		x = x->lc;
	}

}

template <typename T,typename VST>
void travIn_I1(BinNodePosi(T) x, VST & visit)
{
	Stack<BinNodePosi(T)> S;
	while(true)
	{
		goAlongLeftBranch(x, S);
		if (S.empty())
		{
			break;
		}
		x = S.pop();
		visit(x->data);
		x = x->rc;
	}
}
