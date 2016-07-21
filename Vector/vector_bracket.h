#pragma once 

template<typename T >
T& Vector<T>::operator[] (Rank R)const//重载下标操作
{
    return _elem[R];
}