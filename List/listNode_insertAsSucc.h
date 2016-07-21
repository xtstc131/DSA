#pragma once
template <typename T>
ListNode<T>* ListNode<T>::insertAsSucc(T const& e)//将E紧靠当前结点之后插入于当前节点所属列表（设置哨兵节点header）
{
	ListNodePosi(T) x = new ListNode(e, this, succ);//创建新节点
	succ->pred = x; succ = x;//设置逆向链接
	return x;//返回新节点的位置
}
