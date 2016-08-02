#pragma once
template <typename T>
ListNode<T>* List<T>::find(T const& e, int n, ListNode<T>* p) const
{
	while( 0 < n -- )
	{
		if (e == (p = p->pred)->data)
			return p;
	}
	return nullptr;
}
