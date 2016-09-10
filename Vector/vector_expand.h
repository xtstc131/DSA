#pragma once

template <typename T>
void Vector<T>::expand()//向量空间不足时扩容
{
    if(_size < _capacity) return;//如果未满员，不必扩容
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;  //容量不低于最小容量
    T * oldElem = _elem ;//保存下原始指针的地址，因为执行new操作以后_elem会改变原始的地址。。
	_elem = new T[_capacity <<= 1];//容量加倍
    for(int i = 0 ; i < _size ; i++)
    {
        _elem[i] = oldElem[i];//复制原向量的内容(T 为基本类型 ，或者已经重载赋值操作符"=")
    }
    delete[]oldElem;    //释放原空间
}