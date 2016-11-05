#pragma once
template <typename K, typename V>
bool Hashtable<K, V>::remove(K k)
{
	int r = probe4Hit(k);
	if (!ht[r]) return false; //�����ɾ����λ���ǿ�ֵ��ô�ͷ���false
	delete ht[r]; ht[r] = nullptr;
	markAsRemoved(r);//�ͷŴ���������������ɾ����ǣ����´����ܸ���,����true
	N--;
	if (N && N < M / 8)//����������С��1/8�� ��ô�Ͱ�Ͱ����ĳ��ȼ���һ��
		resize(M / 2);
	return true;
}
