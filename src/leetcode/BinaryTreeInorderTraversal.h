/*
 * BinaryTreeInorderTraversal.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *  1
 *   \
 *    2
 *   /
 *  3
 *
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * PS: OJ's Binary Tree Serialization:
 * The serialization of a binary tree follows a level order traversal,
 * where '#' signifies a path terminator where no node exists below.
 */

#ifndef BINARYTREEINORDERTRAVERSAL_H_
#define BINARYTREEINORDERTRAVERSAL_H_

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
void inorderTraversal(TreeNode* node, vector<int> &result) {
	if (node == NULL)
		return;
	inorderTraversal(node->left, result);
	result.push_back(node->val);
	inorderTraversal(node->right, result);
}

// 2nd method: Iteratively, using stack, DFS idea
vector<int> inorderTraversal(TreeNode *node) {
	vector<int> result;
	if (node == NULL)
		return result;
	stack<TreeNode*> st;
	TreeNode* cur_node = node;
	while (!st.empty() || cur_node != NULL) {
		if (cur_node != NULL) {
			st.push(cur_node);
			cur_node = cur_node->left; // visit left subtree
		} else {
			cur_node = st.top();
			st.pop();
			result.push_back(cur_node->val); // visit root
			cur_node = cur_node->right; // visit right subtree
		}
	}
	return result;
}

#endif /* BINARYTREEINORDERTRAVERSAL_H_ */
