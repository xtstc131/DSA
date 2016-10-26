
#pragma once

#include <iostream>
using namespace std;
#include "huffman_pq.h"
inline int * statistics(string& sample_text_file);//statistic frequence of each letter					
HuffForest* initForest(int*); //创建编码树森林
HuffTree* generateTree(HuffForest*); //构造编码树
map<char, string>* generateMap(HuffTree*); //由编码树转换为编码表
int encode(map<char, string>*, bitmap*, string & ); //明文的编码，返回编码长度
void decode(HuffTree*, bitmap*, int,string &result); //二进制串的解码
#include "Huffman_pq_implementation.h"