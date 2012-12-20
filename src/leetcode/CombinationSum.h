/*
 * CombinationSum.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 */

#ifndef COMBINATIONSUM_H_
#define COMBINATIONSUM_H_

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector < vector<int> > result;
	sort(candidates.begin(), candidates.end()); // original array will be sorted
	if (candidates[0] > target) // no matching result
		return result;
	vector<int> combination;
	getCombinations(candidates, target, 0, combination, result);
	return result;
}

void getCombinations(vector<int> &candidates, int target, size_t i,
		vector<int> combination, vector<vector<int> > &result) {
	if (target <= 0) {
		if (target == 0) // found a matching combination
			if (find(result.begin(), result.end(), combination) == result.end()) // no duplicated
				result.push_back(combination);
		return;
	}
	if (i == candidates.size()) // reach the end, cannot found a matching
		return;

	for (int j = 0; j * candidates[i] <= target; j++) { // can pick the same value unlimited times, or 0 time
		if (j != 0)
			combination.push_back(candidates[i]);
		getCombinations(candidates, target - j * candidates[i], i + 1,
				combination, result); // get the next item
	}
}

#endif /* COMBINATIONSUM_H_ */
