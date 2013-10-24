/*
 * MaximumSubarray.h
 *
 *  Created on: Dec 17, 2012
 *      Author: MiTKooK
 */

/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#ifndef MAXIMUMSUBARRAY_H_
#define MAXIMUMSUBARRAY_H_

#include <climits>  // INT_MIN
using namespace std;

/*
 * idea: if has max subarray A[i...j], then sum of subarray A[0...i-1] must < 0
 * note: special case, all integers < 0
 *
 * O(n)
 */
int maxSubArray(int A[], int n) {
	int max = A[0], max_neg = A[0], sum = 0;
	bool flag = false; // test if A[] contains all negative integers
	for (int i = 0; i < n; i++) {
		if (A[i] >= 0)
			flag = true;
		else if (A[i] > max_neg)
			max_neg = A[i];

		sum += A[i];
		if (sum < 0) // previous numbers could not make any contribution for max sum subarray
			sum = 0;
		else if (sum > max)
			max = sum;
	}

	return flag ? max : max_neg;
}

/*
 * Divide and Conquer method:
 * assume the middle number is in maxSubArray
 * 1. compute left maxSubArray[l...mid] and right maxSubArray[mid...r] respectively
 * 2. combine the result if the integrated result is bigger; otherwise choose the bigger side
 * call : maxSubarray_Divide_Conquer(A, 0, n-1)
 *
 * O(nlogn) time and space complexity
 */
int maxSubArray_Divide_Conquer(int A[], int left, int right) {
	if (left > right)
		return INT_MIN;
	if (left == right)
		return A[left];
	int mid = (left + right) / 2;
	int lmax = A[mid], rmax = A[mid], sum = 0;
	for (int i = mid; i >= left; i--) {
		sum += A[i];
		lmax = max(lmax, sum); // #include <algorithm>
	}
	sum = 0;
	for (int i = mid; i <= right; i++) {
		sum += A[i];
		rmax = max(rmax, sum);
	}
	int result = max(maxSubArray_Divide_Conquer(A, mid + 1, right),
			maxSubArray_Divide_Conquer(A, left, mid - 1));
	return max(result, lmax + rmax - A[mid]);
}

#endif /* MAXIMUMSUBARRAY_H_ */
