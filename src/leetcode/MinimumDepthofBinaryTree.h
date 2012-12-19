/*
 * MinimumDepthofBinaryTree.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

#ifndef MINIMUMDEPTHOFBINARYTREE_H_
#define MINIMUMDEPTHOFBINARYTREE_H_

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

// 1st method: Recursive
int minDepth_Recursive(TreeNode *root) {
	if (root)
		return 0;

	int min_left = minDepth_Recursive(root->left);
	int min_right = minDepth_Recursive(root->right);

	if (min_left == 0 || min_right == 0)
		return max(min_left, min_right) + 1;

	return min(min_left, min_right) + 1;
}

// 2nd method: Non-Recursive
/*
 * idea: Use BFS to iterate the tree, keep track of the "level" you're currently at.
 * When a leaf node shows up, return the level number.
 */
int minDepth(TreeNode *root) {
	if (!root)
		return 0;

	queue<TreeNode *> que;
	que.push(root);
	que.push(NULL); // mark as end of a level
	TreeNode * node = NULL;
	int depth = 1;

	while (!que.empty()) {
		node = que.front();
		que.pop();

		if (!node) {
			depth++;
			if (!que.empty())
				que.push(NULL); // place the end-mark for next level
		} else {
			if (!node->left && !node->right) {
				break;
			} else {
				if (node->left)
					que.push(node->left);
				if (node->right)
					que.push(node->right);
			}
		}
	}

	return depth;
}

#endif /* MINIMUMDEPTHOFBINARYTREE_H_ */
