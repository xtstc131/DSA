#pragma once
template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e)//��E������ǰ���֮ǰ�����ڵ�ǰ�ڵ������б������ڱ��ڵ�header��
{
	ListNodePosi(T) x = new ListNode(e, pred, this); // �����½ڵ�
	pred->succ = x; pred = x;//������������
	return x;//�����½ڵ��λ��
}


