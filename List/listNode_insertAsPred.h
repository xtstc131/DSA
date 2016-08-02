#pragma once
template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, pred, this); // 创建新节点
	pred->succ = x; pred = x;//设置正向链接
	return x;//返回新节点的位置
}
