#pragma once
#include"dictionary.h"
#include"../BitMap/bitmap.h"
#include "../entry/entry.h"
#include "../prime/primenlt.h"
template<typename K ,typename V>
class Hashtable :Dictionary<K,V>
{
private:
	Entry<K, V>** ht;
	int M;//桶的容量
	int N;//词条的数量
	bitmap * lazyRemoval;//懒惰删除印记
#define lazilyRemoved(x) (lazyRemoval->test(x))
#define markAsRemoved(x) (lazyRemoval->set(x))
protected:
	int probe4Hit(const K & k);//找到词条对应的值
	int probe4Free(const K & k);//找到首个可以用的桶
	void resize(int n); //重新分配桶的大小，让填充因子保持在1/8 - 1/2之间
public:
	explicit Hashtable(int c = 5)
	{
		M = primeNLT(c, 1048576, "../prime/prime-1048567-bitmap.txt");
		N = 0; 
		ht = new Entry<K, V>*[M];
		memset(ht, 0, sizeof(Entry<K, V>*) * M);
		lazyRemoval = new bitmap(M);
	}
	~Hashtable()
	{
		for(int i = 0 ; i < M ; i++)
		{
			if (ht[i])
				delete ht[i];
		}
		delete ht;
		delete lazyRemoval;
	}
	int size()const override
	{
		return N;
	}
	bool put(K, V) override;
	V * get(K) override;
	bool remove(K k) override;

};
#include"hashmap_implementation.h"