/*
 * BinaryTreeLevelOrderTraversal.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * 		3
 *	   / \
 *	  9  20
 *	 	/  \
 *     15   7
 * return its level order traversal as:
 * [
 *  [3],
 *  [9,20],
 *  [15,7]
 * ]
 */

#ifndef BINARYTREELEVELORDERTRAVERSAL_H_
#define BINARYTREELEVELORDERTRAVERSAL_H_

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

// idea: BFS, using queue
vector<vector<int> > levelOrder(TreeNode *root) {
	vector < vector<int> > result;
	queue<TreeNode*> que;

	if (root)
		que.push(root);
	else
		return result;

	vector<int> cur_row;
	int cur_level_num = 1, next_level_num = 0;
	TreeNode* cur_node = NULL;

	while (!que.empty()) {
		cur_node = que.front();
		que.pop(); // visited
		cur_level_num--; // mark visited
		cur_row.push_back(cur_node->val);
		if (cur_node->left) {
			que.push(cur_node->left);
			next_level_num++;
		}
		if (cur_node->right) {
			que.push(cur_node->right);
			next_level_num++;
		}
		if (cur_level_num == 0) { // if all node in this level are visited
			result.push_back(cur_row);
			cur_row.clear();
			cur_level_num = next_level_num;	// start to get the next level
			next_level_num = 0;
		}
	}
	return result;
}

#endif /* BINARYTREELEVELORDERTRAVERSAL_H_ */
