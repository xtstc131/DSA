#pragma once
template <typename K, typename V>
void Hashtable<K, V>::resize(int n)
{
	int old_capcity = M;  Entry<K, V>** old_ht = ht;
	M = primeNLT(n, 1048576, "../prime/prime-1048567-bitmap.txt");
	N = 0;
	ht = new Entry<K, V>*[M];
	memset(ht, 0, sizeof(Entry<K, V>*)*M);

	delete lazyRemoval; lazyRemoval = new bitmap(M);//���³�ʼ������ɾ������
	for(int i = 0 ; i < old_capcity; i++)
	{
		if (old_ht[i])//�Ѿ������Ԫ����һ������������
			put(old_ht[i]->key, old_ht[i]->value);
	}
	delete old_ht;//ԭ����ŵĴ������Ѿ�ת�Ƶ����µ�Ͱ���飬����ֻ��Ͱ���鱾���ͷžͿ�����
}
