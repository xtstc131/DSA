#pragma once

template <typename T, typename VST> //Ԫ�����͡�������
void travIn_I4(BinNodePosi(T) x, VST& visit) { //���������������������#4������ջ���־λ��
	while (true)
		if (HasLChild(*x)) //��������������
			x = x->lc; //�������������
		else { //����
			visit(x->data); //���ʵ�ǰ�ڵ㣬��
			while (!HasRChild(*x)) //���ϵ������ҷ�֧��
			{
				if (!((x = x->succ()))) return; //������ֱ�Ӻ�̣���û�к�̵�ĩ�ڵ㴦��ֱ���˳���
				visit(x->data);
			}//�����µĵ�ǰ�ڵ�
			x = x->rc; //��ֱ�����ҷ�֧����ת��ǿյ�������
		}
}