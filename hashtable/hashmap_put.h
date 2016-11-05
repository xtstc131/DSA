#pragma once
template <typename K, typename V>
int Hashtable<K, V>::probe4Free(const K& k)
{
	int r = probe4Hit(k);
	while (ht[r])
	{
		r = (r + 1) % M;
	}
	return r;
}


template <typename K, typename V>
bool Hashtable<K, V>::put(K k, V v)
{
	if (ht[probe4Hit(k)]) return false;
	int r = probe4Free(k);
	ht[r] = new Entry<K, V>(k, v);
	++N;
	if (N * 2 > M) resize(M * 2);//如果填充因子大于1/2， 那么就把桶数组的长度增加一半
	return true;
}
