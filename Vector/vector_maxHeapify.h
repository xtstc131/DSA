#pragma once

inline Rank parent(Rank i )
{
	return i / 2;
}
inline void swap(Rank & a1 ,Rank & a2)
{
	Rank temp = a1;
	a1 = a2;
	a2 = temp;
}
inline Rank left(Rank i )
{
	return 2 * i;
}

inline Rank right(Rank i)
{
	return 2 * i + 1;
}
template <typename T>
void Vector<T>::maxHeapify(int index)
{
	Rank l = left(index);
	Rank r = right(index);
	Rank largest = 0;
	if (l <= size() - 1 && _elem[l] > _elem[index])
		largest = l;
	else
		largest = index;
	if (r <= size() - 1 && _elem[r] > _elem[largest])
		largest = r;
	if (largest != index)
		swap(index, largest);
	maxHeapify(largest);
}

