#pragma once
template <typename T>
ListNode<T>* ListNode<T>::insertAsSucc(T const& e)//��E������ǰ���֮������ڵ�ǰ�ڵ������б������ڱ��ڵ�header��
{
	ListNodePosi(T) x = new ListNode(e, this, succ);//�����½ڵ�
	succ->pred = x; succ = x;//������������
	return x;//�����½ڵ��λ��
}
