#pragma once
template <typename T>
int List<T>::clear()
{
	auto oldsize = _size;
	while (0 < _size) remove(header->succ);
	return oldsize;
}
