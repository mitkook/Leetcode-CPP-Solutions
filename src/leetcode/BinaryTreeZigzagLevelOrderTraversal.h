/*
 * BinaryTreeZigzagLevelOrderTraversal.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its zigzag level order traversal as:
 * [
 *  [3],
 *  [20,9],
 *  [15,7]
 * ]
 */

#ifndef BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_
#define BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_

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

/*
 * idea: using two stacks, one for current level, another for next level. use a boolean value to record traversal direction for each scan.
 * algorithm based on BFS
 */
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector < vector<int> > result;
	if (root == NULL)
		return result;

	vector<int> cur_level;
	stack<TreeNode*> currS, nextS;
	currS.push(root);
	TreeNode * cur_node = NULL;
	bool leftToRight = true;

	while (!currS.empty()) {
		while (!currS.empty()) {
			cur_node = currS.top();
			currS.pop();
			cur_level.push_back(cur_node->val);
			if (leftToRight) {
				if (cur_node->left)
					nextS.push(cur_node->left);
				if (cur_node->right)
					nextS.push(cur_node->right);
			} else {
				if (cur_node->right)
					nextS.push(cur_node->right);
				if (cur_node->left)
					nextS.push(cur_node->left);
			}
		}
		result.push_back(cur_level);
		cur_level.clear();
		swap(currS, nextS);
		leftToRight = !leftToRight;
	}
	return result;
}

#endif /* BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_ */
