#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY 3

template<typename T>class Vector
{
public:
//构造函数
	explicit Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//容量是C 规模是S，初始元素均为V
	{_elem = new T[_capacity = c]; for (_size = 0;  _size < s; _elem[_size] = v); }
	Vector(T const * A, Rank n) { copyFrom(A, 0, n); }//数组整体复制
	Vector(T const * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }//数组区间复制
	Vector(Vector<T> const & V) { copyFrom(V._elem,0,V._size); }//向量整体复制
	Vector(Vector<T> const & V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }//向量区间复制
//析构函数
	~Vector() { delete[]_elem; }//释放内部空间
//只读访问接口
	Rank size() const{ return _size; }//返回向量的规模
	bool empty() const { return !_size; }//size是0 就返回TURE ,否则返回FAULSE
	int disordered()const;//判断是否是有序的，有序返回0,不是有序返回正整数
	Rank find(T const & e)const { return find(e, 0, _size); }//无序向量的整体查找
	Rank find(T const & e, Rank lo, Rank hi) const;//无序向量区间查找
	Rank search(T const & e)const//有序向量整体查找
	{
		return(0 >= _size ? -1 : search(e, 0, _size));
	}
	Rank search(T const & e, Rank lo, Rank hi)const;//有序向量区间查找;
//可写访问接口
	T & operator[](Rank r)const;//重载下标操作符，模仿数组形式引用各种元素
	Vector<T> & operator = (Vector<T> const &);//重载赋值操作符，方便向量间的赋值
	T remove(Rank r);//删除秩为r的元素，并返回它
	int remove(Rank lo, Rank hi);//删除在[lo,hi)之间的元素，并返回区间的长度
	Rank insert(Rank r, T const & e);//插入元素
	Rank insert(T const & e) { return insert(_size, e); }//默认在末尾加入元素
	void sort(Rank lo, Rank hi);//对区间[lo,hi)排序
	void sort() { sort(0, _size); }//默认整体排序
	void unsort(Rank lo, Rank hi);//对区间[lo,hi)弄乱
	void unsort() { sort(0, _size); }//默认整体弄乱
	int deduplicate();//无序去重
	int uniquify();//有序去重
	
//遍历
	void traverse(void(*)(T&));//遍历(使用函数指针，只读或局部性修改)
	template<typename VST>void traverse(VST&);//遍历(使用函数对象，可全局修改)
protected:
	Rank _size;//规模
	int _capacity;//容量
	T * _elem;//数据区，理解成用来储存向量的数组吧
	void swap(T T1, T T2) { T temp; temp = T1; T1 = T2; T2 = temp; }
	void copyFrom(T const * A, Rank lo, Rank hi);//复制数组区间[lo,hi)
	void expand();//空间不足时扩容
	void shrink();//填装因子过小时压缩
	bool bubble(Rank lo, Rank hi);//扫描交换
	void bubbleSort(Rank lo, Rank hi);//冒泡排序
	Rank max(Rank lo, Rank  hi);//选取最大元素
	void selectionSort(Rank lo, Rank hi);//选择排序
	void merge(Rank lo, Rank mi, Rank hi);//归并算法
	void mergeSort(Rank lo, Rank hi);//归并排序算法
	//轴点构造
	//快速排序
	//堆排序
};
#include"vector_implementation.h"