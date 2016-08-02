#pragma once
template <typename T>
List<T>::List(List<T> const& L)
{
	copyNode(L.first(), L._size);
}

template <typename T>
List<T>::List(List<T> const& L, Rank r, int n)
{
	copyNode(L[r], n);
}

template <typename T>
List<T>::List(ListNode<T>* p, int n)
{
	copyNode(p, n);
}
