/*
 * BinaryTreeMaximumPathSum.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *
 *    1
 *   / \
 *  2   3
 *
 * Return 6.
 */

#ifndef BINARYTREEMAXIMUMPATHSUM_H_
#define BINARYTREEMAXIMUMPATHSUM_H_

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

int maxPathSum(TreeNode *root) {
	if (root == NULL)
		return 0;
	int maxSum = root->val;
	maxPathSum(root, maxSum);
	return maxSum;
}

// Recursive method
int maxPathSum(TreeNode *node, int &maxSum) {
	if (node == NULL)
		return 0;

	int leftMax = maxPathSum(node->left, maxSum);
	int rightMax = maxPathSum(node->right, maxSum);

	int path_with_node = node->val;
	if (leftMax > 0)
		path_with_node += leftMax;
	if (rightMax > 0)
		path_with_node += rightMax;

	if (path_with_node > maxSum)
		maxSum = path_with_node;

	return max(node->val, node->val + max(leftMax, rightMax));
}

#endif /* BINARYTREEMAXIMUMPATHSUM_H_ */
