#pragma once
template <typename T>
int BinNode<T>::size()
{
	auto s = 1;
	if (lc)
	{
		s += lc->size();
	}
	if (rc) 
	{
		s += rc->size();
	}

	return s;
}
