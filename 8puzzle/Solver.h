#pragma once
#include<queue>
#include<stack>
#include"Board.h"
#include <functional>
using namespace std;
struct Node
{
	Board board;
	Node * prevBoard;
	int numMoves;

	Node(Board &b, Node * p)
	{
		board = b;
		prevBoard = p;
		if (!prevBoard)
		{
			numMoves = 0;
		}
		else
			numMoves = prevBoard->numMoves + 1;
	}
	bool operator <= (const Node & n)const
	{
		return board.manhattan() <= n.board.manhattan() ? true : false;
	}
	bool operator > (const Node & n)const
	{
		return board.manhattan() > n.board.manhattan() ? true : false;
	}
	bool operator == (const Node & n) const
	{
		return  board.manhattan() == board.manhattan();
	}
};
class Solver
{
public:
	explicit Solver(Board & initial)
	{
		solvable = false;

		lastNode = nullptr;
		open.push(Node(initial, nullptr));
		
		//consider the situation of the twin boards
		Board bTwin = Board(initial);
		lastNode_twin = nullptr;
		initial.twin(bTwin);
		open_twin.push(Node(bTwin, nullptr));	
	}
	void sovleThePuzzle()
	{
		bool alt = false;
		//Main prosess of A star Algorithm
		while (true)
		{
			if (!alt)
			{

				auto minF = open.top(); open.pop();
				closed.push(minF);//插入到CLOSED栈，这样以此出栈就是寻路过程
				if (minF.board.isGoal())
				{
					solvable = true;
					break;
				}
				Vector<Board>  neighbor_boards;
				minF.board.neighbors(neighbor_boards);
				for (auto i = 0; i < neighbor_boards.size(); ++i)
				{
					auto *node = new Node(neighbor_boards[i], &minF);
					if (*lastNode == *node)
					{
						continue;
					}
					lastNode = node;
					open.push(*node);
				}
			}
			else
			{
				auto minF = open_twin.top(); open_twin.pop();
				if (minF.board.isGoal())
				{
					solvable = true;
					break;
				}
				Vector<Board>  neighbor_boards;
				minF.board.neighbors(neighbor_boards);
				for (auto i = 0; i < neighbor_boards.size(); ++i)
				{
					auto *node = new Node(neighbor_boards[i], &minF);
					if (*lastNode_twin == *node)
					{
						continue;
					}
					lastNode_twin = node;
					open_twin.push(*node);
				}
			}
		}
	}
	bool isSovable() const
	{
		return solvable;
	}
	int moves()
	{
		return closed.top().numMoves;
	}
private:
	queue<Board> PQ;
	Node *lastNode;
	Node * lastNode_twin;
	//
	bool solvable;
	
	priority_queue<Node, vector<Node>, greater<Node>> open;
	priority_queue<Node, vector<Node>, greater<Node>> open_twin;
	//输出结果栈
	stack<Node> closed;
};