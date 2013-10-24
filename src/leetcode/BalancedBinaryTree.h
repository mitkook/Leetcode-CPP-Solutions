/*
 * BalancedBinaryTree.h
 *
 *  Created on: Dec 18, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which
 * the depth of the two subtrees of every node never differ by more than 1.
 */

#ifndef BALANCEDBINARYTREE_H_
#define BALANCEDBINARYTREE_H_

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

// post traversal : O(n)
bool isBalanced(TreeNode *root) {
	if (root == NULL)
		return true;
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	if (abs(leftHeight - rightHeight) > 1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
}

int getHeight(TreeNode *root) {
	if (root == NULL)
		return 0;
	return (1 + max(getHeight(root->left), getHeight(root->right)));
}

#endif /* BALANCEDBINARYTREE_H_ */
