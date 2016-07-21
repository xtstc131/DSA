#pragma once

template<typename T >	//元素类型
void Vector<T>::copyFrom(T const * A ,Rank lo , Rank hi)	//数组区间A[lo,hi)复制向量
{
	_elem = new T[_capacity = 2 * (hi - lo)];_size = 0;//分配空间，规模清零
	while (lo<hi)//A[lo,hi)内的元素逐一
		_elem[_size++] = A[lo++];//复制到_elem[0,hi-lo)
}