#pragma once
template <typename T>
void Vector<T>::heapSort()
{
	for (auto i = size() - 1; i >= 0; i--)
		maxHeapify(i);
}
