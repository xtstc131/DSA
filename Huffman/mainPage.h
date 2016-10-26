#pragma once
#include "huffman_test.h"
#include <sstream>
int Map[10][20] = {

	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0 },
	{ 1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1 },
	{ 1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,0,0,0,0 },
	{ 1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1 },
	{ 1,0,1,1,0,1,0,0,0,0,1,0,1,1,1,1,0,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1 },
	{ 1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0 },
	{ 1,1,1,1,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0 },
	{ 1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0 }
};
int * a;
int n = 0;

string text_s("C:\\Users\\mallox\\Documents\\Visual Studio 2015\\Projects\\DSA\\Huffman\\test_sample.txt");
string code_string("C:\\Users\\mallox\\Documents\\Visual Studio 2015\\Projects\\DSA\\Huffman\\code_sample.txt");
string result_path("C:\\Users\\mallox\\Documents\\Visual Studio 2015\\Projects\\DSA\\Huffman\\result.txt");
string result("");
string read_s("");
HuffTree * huffTree;
HuffForest * huffForest;
bitmap * code = new bitmap;
inline void printTheme()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (!j)
				cout << "		";
			if (!Map[i][j])
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "\n*****************************************************\n";
	cout << endl;
}

inline void printMenu()
{
	cout << "		   S----Statistic" << endl;
	cout << "		   B----Built Tree" << endl;
	cout << "		   T----Traverse" << endl;
	cout << "		   C----Code" << endl;
	cout << "		   D----Decode" << endl;
	cout << "		   P----Print" << endl;
	cout << "		   X----Exit" << endl;
}

inline void statisticMain()
{

	a = statistics(text_s);
	for (int i = 0; i < N_CHAR; i++)
		cout << char(0x20 + i) << ":" << a[i] << "	\n";
	cout << endl;
}

inline void builrHuffTreeMain()
{
	huffForest = initForest(a);
	huffTree = generateTree(huffForest);
	cout << "Built HuffMan Tree Success\n";
}

inline void traverseHuffTreeMain()
{
	huffTree->preTrav();
	cout << endl;
	huffTree->levelTrav();
	cout << endl;
	huffTree->inTrav();
	cout << endl;
}

inline void CodeMain(int &x, string & readS)
{

	auto map = generateMap(huffTree);
	x = encode(map, code, readS);
	string strCode = code->bit2string(n);
	ofstream out(code_string);
	out << strCode;
	out.close();
}

inline void DecodeMain(const int n)
{
	cout << "Decode:\n\n";
	decode(huffTree, code, n, result);
	ofstream out(result_path);
	out << result;
	out.close();
}

inline void readFile(ifstream & in, string & data)
{
	stringstream buffer;
	buffer << in.rdbuf();
	data = buffer.str();
}

inline void printMain()
{
	ifstream in_text(text_s); string text;
	ifstream in_code(code_string); string code;
	ifstream in_result(result_path); string result;

	cout << "\n							Text:\n\n";
	readFile(in_text, text);
	cout << text << endl;

	cout << "\n							Code:\n\n";
	readFile(in_code, code);
	cout << code << endl;

	cout << "\n							Result:\n\n";
	readFile(in_result, result);
	cout << result << endl;


}

inline void mainLoop()
{

	printTheme(); char ch;
	printMenu();
	while (cin >> ch)
	{
		ch = toupper(ch);
		switch (ch)
		{
		case 'S':statisticMain(); break;
		case 'B':builrHuffTreeMain(); break;
		case 'T':traverseHuffTreeMain(); break;
		case 'C':
			cout << "Input your string which you want to encode :" << endl;
			getchar();
			getline(cin, read_s);
			CodeMain(n, read_s);
			break;
		case 'D':DecodeMain(n); break;
		case 'P': printMain(); break;
		case 'X': exit(0); break;
		default:
			cout << "Please input correct optional\n";
			break;

		}
		printMenu();
	}
}