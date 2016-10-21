#pragma once
#include"huffman_pq.h"
using namespace std;
inline int * statistics(string sample_text_file)
{
	auto freq = new int[N_CHAR];
	memset(freq, 0, N_CHAR);
	char ch;
	ifstream inf;
	inf.open(sample_text_file,ios::in);
	while (!inf.eof())
	{
		inf.get(ch);
		if (ch >= 0x20 && ch <= 0x80)
		{
			freq[ch - 0x20]++;
		}
	}
	inf.close();
	return freq;
}
inline HuffForest* initForest(int * freq)
{
	HuffForest * forest = new HuffForest(N_CHAR);
	for (auto i = 0; i < N_CHAR; i++)
	{
		BinTree<HuffChar>* tree = new BinTree<HuffChar>();
		tree->insertAsRoot(HuffChar(0x20 + i, freq[i]));
		forest->append(tree);
	}
	return forest;
}
inline	HuffTree* generateTree(HuffForest * forest)
{

	while (1 < forest->size())
	{
		HuffTree *ht1 = forest->delMin();
		HuffTree *ht2 = forest->delMin();
		HuffTree * S = new HuffTree();
		S->insertAsRoot(HuffChar('^', ht1->root()->data.weight + ht2->root()->data.weight));
		S->attachAsLC(S->root(), ht1); S->attachAsRC(S->root(), ht2);
		forest->append(S);
	}
	HuffTree *tree = forest->delMin();
	return tree;
}
