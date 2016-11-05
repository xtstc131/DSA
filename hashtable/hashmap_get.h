#pragma once
template <typename K, typename V>
int Hashtable<K, V>::probe4Hit(const K& k)
{
	int r = hashCode(k) % M;
	while ((ht[r] && (k != ht[r]->key)) || (!ht[r] && lazilyRemoved(r)))
		r = (r + 1) % M;
	return r;
}

template <typename K, typename V>
V* Hashtable<K, V>::get(K k)
{
	int r = probe4Hit(k); return ht[r] ? &(ht[r]->value) : nullptr;
}

