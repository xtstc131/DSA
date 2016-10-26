#pragma once
#include"huffman_pq.h"
using namespace std;
int * statistics(string& sample_text_file)//statistic frequence of each letter										  //store them into a int array
{
	auto freq = new int[N_CHAR];
	memset(freq, 0, sizeof(int) * N_CHAR);
	char ch;
	ifstream inf(sample_text_file, ios::in);//file stream obj
	if (!inf) cout << "Wrong Path" << endl;
	while (!inf.eof())//judge weather the file come to the end 
	{
		inf.get(ch);//read the current letter and point to the next 
		if (ch >= 0x20 && ch <= 0x80)//if the letter is visalble then add its counts 
		{
			freq[ch - 0x20]++;
		}
	}
	freq[ch - 0x20]--;//为什么会有问题呢 
	inf.close();//close the file,it'text_s a good custom
	return freq;//return int array 
}
inline HuffForest* initForest(int * freq)//initial the HuffForest(made by PQ),
										 //for we may take the smallest tree in 
										 //o(lgn) time.(= =)
{
	HuffForest * forest = new HuffForest;
	for (auto i = 0; i < N_CHAR; i++)
	{
		HuffTree* tree = new HuffTree;//reInit at each loop
		if (freq[i] != 0)
		{
			tree->insertAsRoot(HuffChar(0x20 + i, freq[i]));//
			forest->push(tree);
		}//append tree( which only has a root node to ) the forest
	}

		return forest;

}
HuffTree* generateTree(HuffForest * forest)
{
	while (1 < forest->size())
	{
		HuffTree *ht1 = forest->top();
		forest->pop();
		HuffTree *ht2 = forest->top();
		forest->pop();
		HuffTree * S = new HuffTree();
		//	cout << ht1->root()->data.weight <<"\n"<<ht2->root()->data.weight<<endl;
		S->insertAsRoot(HuffChar('^', ht1->root()->data.weight + ht2->root()->data.weight));
		S->attachAsLC(S->root(), ht1); S->attachAsRC(S->root(), ht2);
		forest->push(S);
	}
	HuffTree *tree = forest->top();
	return tree;
}
static void generateCT(bitmap * code, int lengh, map<char, string> * huffmap, BinNodePosi(HuffChar) v)
{
	if (!v) return;
	else {
		if (IsLeaf(*v))
		{
			huffmap->insert({ v->data.ch, code->bit2string(lengh) });
		}
		if (HasLChild(*v))
			code->clear(lengh); generateCT(code, lengh + 1, huffmap, v->lc);
		if (HasRChild(*v))
			code->set(lengh); generateCT(code, lengh + 1, huffmap, v->rc);
	}
}

inline map<char, string>* generateMap(HuffTree * tree)
{
	auto huffmap = new map<char, string>();
	bitmap * code = new bitmap;
	generateCT(code, 0, huffmap, tree->root());
	delete code;
	cout << "Generate Map Success\n";
	map<char, string>::iterator it = huffmap->begin();
	for (; it != huffmap->end(); ++it)
		cout <<"["<< it->first<<" "<<it->second<<"]";
	cout << endl;
	return huffmap;
}

inline int encode(map<char, string> * huffmap, bitmap  * codeString, string & S)
{
	int n = 0;
	for (size_t m = S.length(), i = 0; i < m; i++)
	{
		string pCharCode = (*huffmap)[S[i]];

		for (size_t l = pCharCode.length(), j = 0; j < l; j++)
		{
			'1' == pCharCode[j] ? codeString->set(n++) : codeString->clear(n++);
		}
	}
	cout << "Encode success";
	cout << endl;
	return n;
}

inline void decode(HuffTree * tree, bitmap* code, int n, string & result)
{
	BinNodePosi(HuffChar) x = tree->root();
	for (int i = 0; i < n; i++)
	{
		x = code->test(i) ? x->rc : x->lc;
		if (IsLeaf(*x))
		{
			result += x->data.ch; x = tree->root();
		}
	}
	cout << "Decode success\n";
}