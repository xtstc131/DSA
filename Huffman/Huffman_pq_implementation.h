#pragma once
#include"huffman_pq.h"
using namespace std;
inline int * statistics(string sample_text_file)
{
	auto freq = new int[N_CHAR];
	memset(freq, 0, N_CHAR);
	char ch;
	ifstream inf;
	inf.open(sample_text_file, ios::in);
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
		HuffTree* tree = new HuffTree;
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
static void generateCT(bitmap * code, int lengh, map<char, string> * huffmap, BinNodePosi(HuffChar) v)
{
	if (IsLeaf(*v))
	{
		huffmap->insert({ v->data.ch, code->bit2string(lengh) });
	}
	if (HasLChild(*v))
		code->clear(lengh); generateCT(code, lengh + 1, huffmap, v->lc);

	if (HasRChild(*v))
		code->set(lengh); generateCT(code, lengh + 1, huffmap, v->rc);
}

inline map<char, string>* generateMap(HuffTree * tree)
{
	auto huffmap = new map<char, string>();
	bitmap * code = new bitmap;
	generateCT(code, 0, huffmap, tree->root());
	delete code;
	return huffmap;
}

inline int encode(map<char, string> * huffmap, bitmap  * codeString, char * S)
{
	int n = 0;
	for (size_t m = sizeof(S), i = 0; i < m; i++)
	{
		string pCharCode = (*huffmap)[S[i]];
		if (!pCharCode.empty())pCharCode = (*huffmap)[S[i] + 'A' - 'a'];
		if (!pCharCode.empty())pCharCode = (*huffmap)[' '];
		cout << pCharCode;
		for (size_t l = pCharCode.length(), j = 0; j < l; j++)
		{
			'1' == pCharCode[j] ? codeString->set(n++) : codeString->clear(n++);
		}
	}
	cout << endl;
	return n;
}
inline void decode(HuffTree * tree, bitmap* code, int n)
{
	BinNodePosi(HuffChar) x = tree->root();
	for (int i = 0; i < n; i++)
	{
		x = code->test(i) ? x->lc : x->rc;
		if (IsLeaf(*x)) { printf("%c", x->data.ch); x = tree->root(); }
	}
}