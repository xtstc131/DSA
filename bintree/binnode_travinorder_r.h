#pragma once
template<typename T,typename VST>
void travIn_R(BinNodePosi(T) x, VST & visit)//�����������㷨���ݹ�棩
{
	if (x == nullptr)
		return;
	travIn_R(x->lc, visit);
	visit(x->data);
	travIn_R(x->rc, visit);
}