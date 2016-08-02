#pragma once
template <typename T>
void List<T>::copyNode(ListNode<T>* p , int n)
{
	init();
	while (n--)
	{
		insertAsLast(p->data);
		p = p->succ;
	}
}
