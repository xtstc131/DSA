#pragma once
struct cmp
{
	bool operator()(HuffTree* a , HuffTree*b) const
	{
		return a->root()->data > b->root()->data;
	}
};
typedef priority_queue<HuffTree*,vector<HuffTree*>,cmp>  HuffForest;