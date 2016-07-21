#pragma once

template<typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const & V)//赋值重载
{
    if(_elem) delete[]_elem;//如果原来有东西就释放其空间
    copyFrom(V._elem,0,V.size());//整体复制
    return *this;//返回当前对象的引用，这样可以连续赋值'
}