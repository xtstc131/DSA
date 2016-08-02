#pragma once

template <typename T>
Rank Vector<T>::find(T const & e  ,Rank lo ,Rank hi )const //无序向量的寻找,返回最后一个元素e的位置；失败时返回 lo-1
{
    while((lo < hi--) && (_elem[hi] !=e) );//从后向前，顺序查找
    return hi; //若 hi < lo则寻找失败，否则返回hi即命中元素的秩
}
