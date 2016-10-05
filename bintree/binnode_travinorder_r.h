#pragma once
template<typename T,typename VST>
void travIn_R(BinNodePosi(T) x, VST & visit)//¶þ²æÊ÷±éÀúËã·¨£¨µÝ¹é°æ£©
{
	if (x == nullptr)
		return;
	travIn_R(x->lc, visit);
	visit(x->data);
	travIn_R(x->rc, visit);
}