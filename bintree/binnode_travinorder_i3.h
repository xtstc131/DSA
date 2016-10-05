#pragma once
template <typename T, typename VST> //元素类型、操作器

void travIn_I3(BinNodePosi(T) x, VST& visit) { //二叉树中序遍历算法（迭代版#3，无需辅助栈）
	auto backtrack = false; //前一步是否刚从右子树回溯——省去栈，仅O(1)辅助空间
	while (true)
		if (!backtrack && HasLChild(*x)) //若有左子树且不是刚刚回溯，则
			x = x->lc; //深入遍历左子树
		else { //否则——无左子树或刚刚回溯（相当于无左子树）
			visit(x->data); //访问该节点
			if (HasRChild(*x)) { //若其右子树非空，则
				x = x->rc; //深入右子树继续遍历
				backtrack = false; //并关闭回溯标志
			}
			else { //若右子树空，则
				if ((x = x->succ()) == nullptr) break; //回溯（含抵达末节点时的退出返回）
				backtrack = true; //并设置回溯标志
			}
		}
}