#pragma once
template <typename T>
BinNode<T>* BinNode<T>::insertAsLC(T const& e)
{
	return lc = new BinNode(e, this);
}

template <typename T>
BinNode<T>* BinNode<T>::insertAsRC(T const& e)
{
	return rc = new BinNode(e, this);
}


