#pragma once
template <typename T> void Vector<T>::sort(Rank lo, Rank hi) { //��������[lo, hi)����
	switch (rand() % 5) { //���ѡȡ�����㷨���ɸ��ݾ���������ص����ѡȡ������
	case 1:  bubbleSort(lo, hi); break; //��������
	case 2:  selectionSort(lo, hi); break; //ѡ������ϰ�⣩
	case 3:  mergeSort(lo, hi); break; //�鲢����
	case 4:  heapSort(lo, hi); break; //�������Ժ���ܣ�
	default: quickSort(lo, hi); break; //���������Ժ���ܣ�
	}
	/*DSA*/ //selectionSort(lo, hi);
}