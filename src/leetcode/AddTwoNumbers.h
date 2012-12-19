/*
 * AddTwoNumbers.h
 *
 *  Created on: Dec 18, 2012
 *      Author: MiTKooK
 */

/*
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#ifndef ADDTWONUMBERS_H_
#define ADDTWONUMBERS_H_

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

// O(n)
ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {

	if (!l1)
		return l2;
	if (!l2)
		return l1;

	int sum = 0, carry = 0;

	ListNode *result = NULL, *node = NULL;

	while (l1 || l2) {

		sum = carry;

		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			sum += l2->val;
			l2 = l2->next;
		}

		carry = sum / 10;

		if (result == NULL)
			result = node = new ListNode(sum % 10);
		else {
			node->next = new ListNode(sum % 10);
			node = node->next;
		}
	}

	if (carry == 1)
		node->next = new ListNode(1);

	return result;
}

#endif /* ADDTWONUMBERS_H_ */
