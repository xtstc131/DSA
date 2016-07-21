#pragma once
template <typename T >
 int Vector<T> ::remove(Rank lo , Rank hi)
 {
     if (lo == hi)
     {
         return ;
     }
     while (hi < _size)
     {
         _elem[lo++] = _elem[hi++];
     }
    shrink();
    return hi - lo;
 }