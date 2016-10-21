#pragma once
#include "listnode.h"

template<typename T > class List
{
private:
	int _size;//��ģ
	ListNodePosi(T) header;//ͷ���ձ�
	ListNodePosi(T) trailer;//β���ձ�

protected:
	void init();//�����б�ʱ�ĳ�ʼ��
	int clear();//������еĽڵ�
	void copyNode(ListNodePosi(T), int);//�����б��p���n��
	void merge(ListNodePosi(T) &, int, List<T>&, ListNodePosi(T), int);//�鲢
	void mergesort(ListNodePosi(T) &, int);//�Դ�p��ʼ��������n���ڵ�鲢����
	void selectionSort(ListNodePosi(T), int);//�Դ�p��ʼ��������n���ڵ�ѡ������
	void insertionSort(ListNodePosi(T), int);//�Դ�p��ʼ��������n���ڵ��������

public:
	List() { init(); }
	List(List<T> const & L);
	List(List<T> const & L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	~List();

	//ֻ�����ʽӿ�
	Rank size()const { return _size; }//��ģ
	bool empty()const { return  _size <= 0; }//�п�
	T& operator[](Rank r)const;//���أ�֧��Ѱ�ȷ��ʣ�Ч�ʵͣ�
	ListNodePosi(T) first()const { return header->succ; }//�׽ڵ�λ��
	ListNodePosi(T) last()const { return trailer->pred; }//β�ڵ�λ��
	void valid(ListNodePosi(T) p)//�ж�p�Ƿ�Ϸ�
	{
		return p && (header != p) && (header != p);
	}
	int disordered()const;//�ж��б��Ƿ�������
	ListNodePosi(T) find(T const & e, int n, ListNodePosi(T) p)const;//�����������
	ListNodePosi(T) find(T const & e)//�����б����
	{return find(e, _size, trailer);}
	ListNodePosi(T) search(T const & e, int, ListNodePosi(T) p)const;//����������� 
	ListNodePosi(T) search(T const & e) { search(e, _size, trailer); }//�����б����
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);//��p�����Ժ��n - 1�����ѡ�������
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }//���������
	//��д���ʽӿ�
	ListNodePosi(T) insertAsFirst(T const& e)
	{
		_size++;
		return header->insertAsSucc(e);
	}//��e��Ϊ�׽ڵ����
	ListNodePosi(T) insertAsLast(T const& e)
	{
		_size++;
		return trailer->insertAsPred(e);
	}
	//��e��Ϊβ�ڵ����
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);//��e��Ϊp�ĺ�̲���
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);//��e��Ϊp��ǰ������
	T remove(ListNodePosi(T) p);
	void merge(List<T> &L) { merge(first(), _size, L, L.first(), L._size); }//ȫ�б�鲢
	void sort() { sort(first(), _size); }
	int deduplicate();//����ȥ��
	int uniquify();//����ȥ��
	void reverse();//��������

//����
	void tranverse(void(*) (T &));
	template<typename VST>
	void tranverse(VST&);

};
#include "list_implementation.h"