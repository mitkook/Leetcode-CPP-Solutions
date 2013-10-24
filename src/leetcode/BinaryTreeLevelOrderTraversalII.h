/*
 * BinaryTreeLevelOrderTraversalII.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * 		3
 *	   / \
 *	  9  20
 *	 	/  \
 *     15   7
 * return its bottom-up level order traversal as:
 * [
 *  [15,7],
 *  [9,20],
 *  [3]
 * ]
 */

#ifndef BINARYTREELEVELORDERTRAVERSALII_H_
#define BINARYTREELEVELORDERTRAVERSALII_H_

#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

// idea: using stack instead of queue for BFS
vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector < vector<int> > result;
	if (!root)
		return result;

	stack < vector<TreeNode*> > st;
	vector<TreeNode*>::iterator it;
	vector<TreeNode*> cur_level(1, root);

	while (!cur_level.empty()) {
		st.push(cur_level);
		cur_level.clear();
		for (it = st.top().begin(); it != st.top().end(); ++it) {
			if ((*it)->left)
				cur_level.push_back((*it)->left);
			if ((*it)->right)
				cur_level.push_back((*it)->right);
		}
	}

	vector<int> level;
	while (!st.empty()) {
		for (it = st.top().begin(); it != st.top().end(); ++it)
			level.push_back((*it)->val);
		result.push_back(level);
		level.clear();
		st.pop();
	}
	return result;
}
#endif /* BINARYTREELEVELORDERTRAVERSALII_H_ */
