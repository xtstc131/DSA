#pragma once
template <typename K, typename V>
bool Hashtable<K, V>::remove(K k)
{
	int r = probe4Hit(k);
	if (!ht[r]) return false; //如果待删除的位置是空值那么就返回false
	delete ht[r]; ht[r] = nullptr;
	markAsRemoved(r);//释放词条，并设置懒惰删除标记，更新词条总个数,返回true
	N--;
	if (N && N < M / 8)//如果填充因子小于1/8， 那么就把桶数组的长度减少一半
		resize(M / 2);
	return true;
}
