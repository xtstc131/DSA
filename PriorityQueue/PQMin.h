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
	
	//�п�
	bool isEmpty() const { return !_size; }
	
	//���ش�С
	int size()const 
	{
		return _size;
	}

	//����
	void append(T&);
	
	//��ȡ�Ѷ�Ԫ��
	T getMin();
	
	//�����Ѷ���Ԫ��
	T delMin();
private:
	T * _elem;
	int _capicity;
	int _size;
protected:
	//������͸
	int percolateDown(int, int);
	
	//������͸
	int percolateUp(int);
	
	//�ѻ�
	void heapify(int);
};
#include"PqMin_impletation.h"