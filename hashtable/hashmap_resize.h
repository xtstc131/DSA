#pragma once
template <typename K, typename V>
void Hashtable<K, V>::resize(int n)
{
	int old_capcity = M;  Entry<K, V>** old_ht = ht;
	M = primeNLT(n, 1048576, "../prime/prime-1048567-bitmap.txt");
	N = 0;
	ht = new Entry<K, V>*[M];
	memset(ht, 0, sizeof(Entry<K, V>*)*M);

	delete lazyRemoval; lazyRemoval = new bitmap(M);//重新初始化懒惰删除数组
	for(int i = 0 ; i < old_capcity; i++)
	{
		if (old_ht[i])//把就数组的元素逐一插入新数组中
			put(old_ht[i]->key, old_ht[i]->value);
	}
	delete old_ht;//原来存放的词条都已经转移到了新的桶数组，所以只把桶数组本身释放就可以了
}
