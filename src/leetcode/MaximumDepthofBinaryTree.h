/*
 * MaximumDepthofBinaryTree.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#ifndef MAXIMUMDEPTHOFBINARYTREE_H_
#define MAXIMUMDEPTHOFBINARYTREE_H_

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

// 1st method: Recursive
int maxDepth_Recursive(TreeNode *root) {
	if (!root)
		return 0;

	return max(maxDepth_Recursive(root->left), maxDepth_Recursive(root->right))
			+ 1;
}

// 2nd method: Non-Recursive (post-order traversal)
int maxDepth_PostOrderTraversal(TreeNode *root) {
	if (!root)
		return 0;
	stack<TreeNode*> st;
	st.push(root);
	int maxDepth = 0;
	TreeNode *curr = NULL, *prev = NULL;
	while (!st.empty()) {
		curr = st.top();
		if (!prev || prev->left == curr || prev->right == curr) {
			if (curr->left)
				st.push(curr->left);
			else if (curr->right)
				st.push(curr->right);
		} else if (curr->left == prev) {
			if (curr->right)
				st.push(curr->right);
		} else {
			st.pop();
		}
		prev = curr;
		if (st.size() > maxDepth)
			maxDepth = st.size();
	}
	return maxDepth;
}

// 3rd method: Non-Recursive (BFS)
int maxDepth_BFS(TreeNode *root) {
	if (!root)
		return 0;

	queue<TreeNode *> que;
	que.push(root);
	que.push(NULL); // mark as end of a level
	TreeNode * node = NULL;
	int depth = 0;

	while (!que.empty()) {
		node = que.front();
		que.pop();

		if (!node) {
			depth++;
			if (!que.empty())
				que.push(NULL); // place the end-mark for next level
		} else {
			if (!node->left && !node->right) {
				continue;
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

#endif /* MAXIMUMDEPTHOFBINARYTREE_H_ */
