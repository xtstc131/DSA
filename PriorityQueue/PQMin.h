#pragma once
#include<iostream>
#include"PQMin_macro.h"
using namespace std;

template<typename T>
class PQMin
{
public:
	//Contructor
	PQMin() = default;
	PQMin( int n);
	PQMin(T * array, int n)
	{
		_size = n;
		_elem = new T[n];
		_capicity = n << 1;
		for(int i = 0 ;i< n ; ++i )
		{
			_elem[i] = array[i];
		}
	}
	//Destructor
	~PQMin();
	
	//判空
	bool isEmpty() const { return !_size; }
	
	//返回大小
	int size()const 
	{
		return _size;
	}

	//插入
	void append(T&);
	
	//获取堆顶元素
	T getMin();
	
	//弹出堆顶的元素
	T delMin();
private:
	T * _elem;
	int _capicity;
	int _size;
protected:
	//向下渗透
	int percolateDown(int, int);
	
	//向上渗透
	int percolateUp(int);
	
	//堆化
	void heapify(int);
};
#include"PqMin_impletation.h"