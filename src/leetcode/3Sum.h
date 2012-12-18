/*
 * 3Sum.h
 *
 *  Created on: Dec 17, 2012
 *      Author: MiTKooK
 */

/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
 * The solution set must not contain duplicate triplets.
 *
 * For example, given array S = {-1 0 1 2 -1 -4},
 *
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 */

#ifndef THREESUM_H_
#define THREESUM_H_

/*
 * idea: assume number "first" is in solution set, determine the other two numbers by iteratively adding "second" and "last" numbers.
 * it requires sorting the array beforehand.
 *
 * O(n^2)
 */
vector<vector<int> > threeSum(vector<int> &num) {
	int N = num.size();
	int first, second, last, sum = 0;
	sort(num.begin(), num.end()); // #include <algorithm>, quick sort
	vector<vector<int> > result; // #include <vector>

	for (first = 0; first < N-2; first++) {
		if(first>0 && num[first] == num[first-1]) { // already picked as the first number in solution set in previous iteration
			continue;
		}
		second = first+1;
		last = N-1;
		while (second < last) {
			sum = num[first] + num[second] + num[last];
			if (sum > 0) last--; // bigger than expected sum, decrease the last (largest in a triplet) number
			else if (sum < 0) second++; // less than expected sum, increase the second number, since the first one is determined
			else {
				vector<int> triplet;
				triplet.push_back(num[first]);
				triplet.push_back(num[second]);
				triplet.push_back(num[last]); // must have first <= second <= last, because array is sorted

				result.push_back(triplet);

				while(second < N-1) {
					second++;
					if(num[second] != num[second-1]) break;// avoid duplicate for second number
				}
				while(last > 0) {
					last--;
					if(num[last] != num[last+1]) break;// avoid duplicate for last number
				}
			}
		}
	}
	return result;
}

#endif /* THREESUM_H_ */
