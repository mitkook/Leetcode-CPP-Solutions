/*
 * 3SumClosest.h
 *
 *  Created on: Dec 17, 2012
 *      Author: MiTKooK
 */

/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#ifndef THREESUMCLOSEST_H_
#define THREESUMCLOSEST_H_

using namespace std;

// O(n^2)
int threeSumClosest(vector<int> &num, int target) {
	int N = num.size();
	if (N < 3) {
		cout<<"Less than three integers!"<<endl;
		return 0;
	}
	sort(num.begin(), num.end()); // #include <algorithm>, quick sort
	int result = num[0] + num[1] + num[2]; // init answer
	int first, second, last, sum;
	for (first = 0; first < N-2; first++) {
		second = first+1;
		last = N-1;
		while (second < last) {
			sum = num[first] + num[second] + num[last];
			if (sum == target) return sum; // found a matching set
			if (abs(sum-target) < abs(result-target)) result = sum; // update the smallest one
			if (sum > target) last--;
			else second++;
		}
	}
	return result;
}

#endif /* THREESUMCLOSEST_H_ */
