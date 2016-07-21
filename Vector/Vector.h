#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY 3

template<typename T>class Vector
{
public:
//���캯��
	explicit Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//������C ��ģ��S����ʼԪ�ؾ�ΪV
	{_elem = new T[_capacity = c]; for (_size = 0;  _size < s; _elem[_size] = v); }
	Vector(T const * A, Rank n) { copyFrom(A, 0, n); }//�������帴��
	Vector(T const * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }//�������临��
	Vector(Vector<T> const & V) { copyFrom(V._elem,0,V._size); }//�������帴��
	Vector(Vector<T> const & V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }//�������临��
//��������
	~Vector() { delete[]_elem; }//�ͷ��ڲ��ռ�
//ֻ�����ʽӿ�
	Rank size() const{ return _size; }//���������Ĺ�ģ
	bool empty() const { return !_size; }//size��0 �ͷ���TURE ,���򷵻�FAULSE
	int disordered()const;//�ж��Ƿ�������ģ����򷵻�0,�������򷵻�������
	Rank find(T const & e)const { return find(e, 0, _size); }//�����������������
	Rank find(T const & e, Rank lo, Rank hi) const;//���������������
	Rank search(T const & e)const//���������������
	{
		return(0 >= _size ? -1 : search(e, 0, _size));
	}
	Rank search(T const & e, Rank lo, Rank hi)const;//���������������;
//��д���ʽӿ�
	T & operator[](Rank r)const;//�����±��������ģ��������ʽ���ø���Ԫ��
	Vector<T> & operator = (Vector<T> const &);//���ظ�ֵ������������������ĸ�ֵ
	T remove(Rank r);//ɾ����Ϊr��Ԫ�أ���������
	int remove(Rank lo, Rank hi);//ɾ����[lo,hi)֮���Ԫ�أ�����������ĳ���
	Rank insert(Rank r, T const & e);//����Ԫ��
	Rank insert(T const & e) { return insert(_size, e); }//Ĭ����ĩβ����Ԫ��
	void sort(Rank lo, Rank hi);//������[lo,hi)����
	void sort() { sort(0, _size); }//Ĭ����������
	void unsort(Rank lo, Rank hi);//������[lo,hi)Ū��
	void unsort() { sort(0, _size); }//Ĭ������Ū��
	int deduplicate();//����ȥ��
	int uniquify();//����ȥ��
	
//����
	void traverse(void(*)(T&));//����(ʹ�ú���ָ�룬ֻ����ֲ����޸�)
	template<typename VST>void traverse(VST&);//����(ʹ�ú������󣬿�ȫ���޸�)
protected:
	Rank _size;//��ģ
	int _capacity;//����
	T * _elem;//�������������������������������
	void swap(T T1, T T2) { T temp; temp = T1; T1 = T2; T2 = temp; }
	void copyFrom(T const * A, Rank lo, Rank hi);//������������[lo,hi)
	void expand();//�ռ䲻��ʱ����
	void shrink();//��װ���ӹ�Сʱѹ��
	bool bubble(Rank lo, Rank hi);//ɨ�轻��
	void bubbleSort(Rank lo, Rank hi);//ð������
	Rank max(Rank lo, Rank  hi);//ѡȡ���Ԫ��
	void selectionSort(Rank lo, Rank hi);//ѡ������
	void merge(Rank lo, Rank mi, Rank hi);//�鲢�㷨
	void mergeSort(Rank lo, Rank hi);//�鲢�����㷨
	//��㹹��
	//��������
	//������
};
#include"vector_implementation.h"