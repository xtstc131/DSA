#pragma once 

template<typename T >
T& Vector<T>::operator[] (Rank R)const//�����±����
{
    return _elem[R];
}