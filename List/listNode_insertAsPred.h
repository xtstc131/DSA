#pragma once
template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e)//将E紧靠当前结点之前插入于当前节点所属列表（设置哨兵节点header）
{
	ListNodePosi(T) x = new ListNode(e, pred, this); // 创建新节点
	pred->succ = x; pred = x;//设置正向链接
	return x;//返回新节点的位置
}


