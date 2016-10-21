#pragma once
#include "listnode.h"

template<typename T > class List
{
private:
	int _size;//规模
	ListNodePosi(T) header;//头部烧饼
	ListNodePosi(T) trailer;//尾部烧饼

protected:
	void init();//创建列表时的初始化
	int clear();//清除所有的节点
	void copyNode(ListNodePosi(T), int);//复制列表从p起的n项
	void merge(ListNodePosi(T) &, int, List<T>&, ListNodePosi(T), int);//归并
	void mergesort(ListNodePosi(T) &, int);//对从p开始的连续的n个节点归并排序
	void selectionSort(ListNodePosi(T), int);//对从p开始的连续的n个节点选择排序
	void insertionSort(ListNodePosi(T), int);//对从p开始的连续的n个节点插入排序

public:
	List() { init(); }
	List(List<T> const & L);
	List(List<T> const & L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	~List();

	//只读访问接口
	Rank size()const { return _size; }//规模
	bool empty()const { return  _size <= 0; }//判空
	T& operator[](Rank r)const;//重载，支持寻秩访问（效率低）
	ListNodePosi(T) first()const { return header->succ; }//首节点位置
	ListNodePosi(T) last()const { return trailer->pred; }//尾节点位置
	void valid(ListNodePosi(T) p)//判断p是否合法
	{
		return p && (header != p) && (header != p);
	}
	int disordered()const;//判断列表是否已排序
	ListNodePosi(T) find(T const & e, int n, ListNodePosi(T) p)const;//无序区间查找
	ListNodePosi(T) find(T const & e)//无序列表查找
	{return find(e, _size, trailer);}
	ListNodePosi(T) search(T const & e, int, ListNodePosi(T) p)const;//有序区间查找 
	ListNodePosi(T) search(T const & e) { search(e, _size, trailer); }//有序列表查找
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);//在p及其以后的n - 1个后继选出最大者
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }//整体最大者
	//可写访问接口
	ListNodePosi(T) insertAsFirst(T const& e)
	{
		_size++;
		return header->insertAsSucc(e);
	}//将e作为首节点插入
	ListNodePosi(T) insertAsLast(T const& e)
	{
		_size++;
		return trailer->insertAsPred(e);
	}
	//将e作为尾节点插入
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);//把e作为p的后继插入
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);//把e作为p的前驱插入
	T remove(ListNodePosi(T) p);
	void merge(List<T> &L) { merge(first(), _size, L, L.first(), L._size); }//全列表归并
	void sort() { sort(first(), _size); }
	int deduplicate();//无序去重
	int uniquify();//有序去重
	void reverse();//逆序排列

//遍历
	void tranverse(void(*) (T &));
	template<typename VST>
	void tranverse(VST&);

};
#include "list_implementation.h"