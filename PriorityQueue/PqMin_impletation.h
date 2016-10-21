#pragma once
//Constructor 
template <typename T>
PQMin<T>::PQMin(int n)
{
	_size = 0;
	_elem = new T[n];
	_capicity = n << 1 + 1;		
}
//Destructor

template<typename T>
PQMin<T>::~PQMin()
{
	delete[]_elem;
	_elem = nullptr;
}
template <typename T>
T PQMin<T>::getMin()
{
	return _elem[0];
}
template <typename T>
T PQMin<T>::delMin()
{
	T  minElem = _elem[0];
	_elem[0] = _elem[--_size];
	percolateDown(0, _size);
	return minElem;
}

template <typename T>
void PQMin<T>::append(T &x)
{
	if (_size + 1 >= _capicity) cerr << "Go die die die" << endl;
	_elem[_size++] = x;
	percolateUp(_size - 1);
}


template<typename T>
inline void Swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

template<typename T>
int PQMin<T>::percolateUp(int i) {
	cout << "I:" << i << endl;
	while (ParentValid(i)) {
		int j = Parent(i);
		if (_elem[i] >= _elem[j]) break;
		Swap(_elem[i], _elem[j]);
		i = j;
	}
	return i;
}

template<typename T>
int PQMin<T>::percolateDown(int j, int r) {
	int child = 2 * j + 1;
	T temp = _elem[j];
	while (child <= r) {
		if ((child < r) && (_elem[child] > _elem[child + 1])) child++;
		if (temp <= _elem[child]) break;
		_elem[Parent(child)] = _elem[child];
		child = LChild(child);
	}
	_elem[Parent(child)] = temp;
	return Parent(child);
}

template<typename T>
void PQMin<T>::heapify(int n) {
	for (int i = LastInternal(n); InHeap(n, i); i--) {
		percolateDown(i, n);
	}
}
