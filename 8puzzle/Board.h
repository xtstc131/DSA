#pragma once
#include"../Vector/Vector.h"
#include <iostream>

class Board
{

public:
	Board() = default;
	Board(const Board & b )
	{
	
		_dimension = b._dimension;
		board = new int*[_dimension];
		for (int i = 0; i < _dimension; ++i)
			board[i] = new int[_dimension];

		for (int i = 0; i < b._dimension * b._dimension; ++i)
			board[i / b._dimension][i % b._dimension] = b.board[i / b._dimension][i % b._dimension];
	}//拷贝构造函数
	Board(int * a, int n)//用一维数组初始化
	{
		_dimension = n;
		board = new int*[n];
		for (auto i = 0; i < n; i++)
			board[i] = new int[n];
		for (auto i = 0; i < n * n; i++)
			board[i / n][i % n] = a[i];
	}


	//	Hamming priority function. The number of blocks in the wrong position, plus the number of moves mad
	//so far to get to the state. Intutively, a state with a small number of blocks in the wrong position 
	//is close to the goal state, and we prefer a state that have been reached using a small number of
	//moves. 
	int hamming() const
	{
		int value = 0;

		for (int i = 0; i < _dimension * _dimension; i++) {

			int r = i / _dimension;

			int c = i%_dimension;

			if (board[r][c] != 0 && board[r][c] != (i + 1)) value++;

		}
		return value;
	}
	/*
	Manhattan priority function.The sum of the distances(sum of the vertical and horizontal distance) from the blocks to their goal positions, plus the number of moves made so far to get to the state.
	*/
	int manhattan() const
	{
		int cnt = 0;

		for (auto i = 0; i < _dimension * _dimension; i++) {

			int r = i / _dimension;

			int c = i%_dimension;

			if (board[r][c] == 0) continue;

			int nr = (board[r][c] - 1) / _dimension;

			int nc = (board[r][c] - 1) % _dimension;

			cnt += abs(nc - c) + abs(nr - r);

		}

		return cnt;
	}

	bool isGoal() const
	{
		return !manhattan;
	}

	static inline void Swap(int & x, int & y)
	{
		auto temp = x;
		x = y;
		y = temp;
	}
	//Find the all neighbors and insert them to the Vector.
	void neighbors(Vector<Board> & v)
	{
		auto x = 0, y = 0;
		//Find the Position of 0 (x , y)
		for (auto i = 0; i < _dimension; i++)
			for (auto j = 0; j < _dimension; j++)
				if (board[i][j] == 0)
				{
					x = i; y = j;
				}
		//Tranverse all four directions and add the valid to Vector. 
		for (auto i = 0; i < 4; i++)
		{
			int Tx = x + tx[i], Ty = y + ty[i];

			if (isValidBoard(Tx, Ty))
			{
				Swap(board[x][y], board[Tx][Ty]);//交换与0的位置就是移动拼图
				v.insert(*this);
				Swap(board[x][y], board[Tx][Ty]);//还原移动，为后面的做考虑
			}
		}
	}
	void  twin(Board & b )  
	{
		int x1, y1;
		int x2, y2;
		do
		{
			x1 = rand() % _dimension;
			y1 = rand() % _dimension;
			x2 = rand() % _dimension;
			y2 = rand() % _dimension;
		
		} while (board[x1][y1] == 0 || board[x2][y2] == 0 || board[x1][y1] == board[x2][y2]);
		//exchange two on-zero elements randomly
		int temp = board[x1][y1];
		board[x1][y1] = board[x2][y2];
		board[x1][y1] = temp;

		b = *this;
		//redo the exchange to make the board array 
		board[x2][y2] = board[x1][y1];
		board[x1][y1] = temp;
		//返回
	}
	bool operator == (const Board & y) const
	{

		for (int i = 0; i < _dimension; i++)
			for (int j = 0; j < _dimension; j++)
				if (board[i][j] != y.board[i][j])
				{
					return false;
				}
		return true;


	}//判断两种拼图是否相等

	Board & operator = (const Board & b)
	{
		if (board != nullptr)
		{
			for (int i = 0; i < _dimension; ++i)
				delete board[i];
			delete []board;
		}
		board = new int *[b._dimension];

		for (int i = 0; i < b._dimension; ++i)
			board[i] = new int[b._dimension];
		for (int i = 0; i < b._dimension * b._dimension; ++i)
			board[i / b._dimension][i % b._dimension] = b.board[i / b._dimension][i % b._dimension];
		return *this;
	}//赋值运算
private:
	unsigned int _dimension;
	int ** board;
	int tx[4] = { 0,1,0,-1 };//用于向四个方向取
	int ty[4] = { 1,0,-1,0 };//不同的Board,顺序是下，右，上，左
	bool isValidBoard(int x, int y) const
	{
		if (x < 0 || x >= _dimension || y < 0 || y >= _dimension)
			return false;
		return true;
	}
};
#include"board_implementation.h"