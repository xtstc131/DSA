#pragma once

template <typename T>
Rank Vector<T>::find(T const & E  ,Rank lo ,Rank hi )const //����������Ѱ��,�������һ��Ԫ��e��λ�ã�ʧ��ʱ���� lo-1
{
    while((lo < hi--) && (_elem[hi] !=E) );//�Ӻ���ǰ��˳�����
    return hi; //�� hi < lo��Ѱ��ʧ�ܣ����򷵻�hi������Ԫ�ص���
}
