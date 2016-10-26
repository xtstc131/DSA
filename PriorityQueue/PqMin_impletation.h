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

//return the element on the top of heap
template <typename T>
T PQMin<T>::getMin()
{
	return _elem[0];
}

//delete the element on the top of heap and return it 
template <typename T>
T PQMin<T>::delMin()
{
	T  minElem = _elem[0];
	cout << minElem;
	_elem[0] = _elem[--_size];
	percolateDown(0, _size);
	return minElem;
}

//add a element and make it to the right position 
template <typename T>
void PQMin<T>::append(T &x)
{
	_elem[_size] = x;
	_size++;
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
	while (ParentValid(i)) {
		int j = Parent(i);//take the value of i's parent 
		if (_elem[i] >= _elem[j])
		{
			break;
		}//to judge weather the child is smaller than it's parent
				  //if not then break the loop 
		Swap(_elem[i], _elem[j]);//else exchange them
		i = j;//percolate up to i's parent 
	}
	return i;//return the final position 
}

template<typename T>
int PQMin<T>::percolateDown(int j, int r) {
	int child = 2 * j + 1;//take value of  j's lChild
	T temp = _elem[j];//把左孩子存入TEMP
	while (child <= r)	//To judge whether the left child is still in the heap.
	{
		if ((child < r) && (_elem[child] > _elem[child + 1])) child++;//Is the lChild is Bigger then we use the rChild
		if (temp <= _elem[child]) 
			break;//if temp is smaller than its smallest child than break the loop
		_elem[Parent(child)] = _elem[child];//else assign child to its parent 
		child = LChild(child);	//percolate down and use the lChild
	}
	_elem[Parent(child)] = temp;//asign temp to its finally position
	return Parent(child);//return the finally position
}

//to make a Priority Queue to a heap.
template<typename T>
void PQMin<T>::heapify(int n) {
	for (int i = LastInternal(n); InHeap(n, i); i--) {
		percolateDown(i, n);
	}
}
