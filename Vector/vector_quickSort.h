#pragma once

template <typename T>
Rank Vector<T>::partion(Rank p, Rank r)
{
	T x = _elem[r];
	auto i = p - 1;
	for (auto j = p ;j <= r -1 ; j ++)
	{
		if (_elem[j] <= x) i = i + 1; swap(_elem[j],x);
	}
	swap(_elem[i + 1],_elem[r]);
	return i + 1;
}

template <typename T>
void Vector<T>::quickSort(Rank p, Rank r)
{
	if (p<r)
	{
		auto q = partion(p, r);
		quickSort(p, q - 1);
		quickSort(q + 1, r);
	}
}
