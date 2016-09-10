#pragma once

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi)
{
	if (hi - lo < 2)return;
	auto mi = (lo + hi) >> 1;
	mergeSort(mi, hi);
	mergeSort(lo, mi);
	merge(lo, mi, hi);
}
