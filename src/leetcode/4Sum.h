/*
 * 4Sum.h
 *
 *  Created on: Dec 17, 2012
 *      Author: MiTKooK
 */

/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
 * The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 * A solution set is:
 * (-1,  0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2,  0, 0, 2)
 */

#ifndef FOURSUM_H_
#define FOURSUM_H_

using namespace std;

/*
 * idea: assume number "first", "second" is in solution set, determine the other two numbers by iteratively adding "third" and "last" numbers.
 * it requires sorting the array beforehand.
 *
 * O(n^3)
 */
vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector < vector<int> > result; // #include <vector>
	sort(num.begin(), num.end()); // #include <algorithm>, quick sort
	int N = num.size();
	int first, second, third, last, sum;

	for (first = 0; first < N - 3; first++) {
		if (first > 0 && num[first] == num[first - 1]) { // already picked as the first number in solution set in previous iteration
			continue;
		}

		for (second = first + 1; second < N - 2; second++) { // iteratively pick the second number in the array
			if (second > (first + 1) && num[second] == num[second - 1]) { // already picked as the second number in solution set in previous iteration
				continue;
			}

			third = second + 1;
			last = N - 1;
			while (third < last) {
				sum = num[first] + num[second] + num[third] + num[last];
				if (sum < target)
					third++;
				else if (sum > target)
					last--;
				else {
					vector<int> quadrlet;
					quadrlet.push_back(num[first]);
					quadrlet.push_back(num[second]);
					quadrlet.push_back(num[third]);
					quadrlet.push_back(num[last]);
					result.push_back(quadrlet); // must have first <= second <= third <= last, because array is sorted

					while (third < N - 1) {
						third++;
						if (num[third] != num[third - 1]) // avoid duplicate for the third number
							break;
					}
					while (last > 0) {
						last--;
						if (num[last] != num[last + 1]) // avoid duplicate for the last number
							break;
					}
				}
			}
		}
	}

	return result;
}

#endif /* FOURSUM_H_ */
