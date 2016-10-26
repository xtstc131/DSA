
#pragma once

#include <iostream>
using namespace std;
#include "huffman_pq.h"
inline int * statistics(string& sample_text_file);//statistic frequence of each letter					
HuffForest* initForest(int*); //����������ɭ��
HuffTree* generateTree(HuffForest*); //���������
map<char, string>* generateMap(HuffTree*); //�ɱ�����ת��Ϊ�����
int encode(map<char, string>*, bitmap*, string & ); //���ĵı��룬���ر��볤��
void decode(HuffTree*, bitmap*, int,string &result); //�����ƴ��Ľ���
#include "Huffman_pq_implementation.h"