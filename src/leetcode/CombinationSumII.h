/*
 * CombinationSumII.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * - All numbers (including target) will be positive integers.
 * - Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
 * - The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 */

#ifndef COMBINATIONSUMII_H_
#define COMBINATIONSUMII_H_

vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
	vector < vector<int> > result;
	int sum = 0;
	for (vector<int>::iterator it = candidates.begin(); it != candidates.end(); it++)
		sum += *it;
	sort(candidates.begin(), candidates.end());
	if (candidates[0] > target || sum < target) // means could not find a matching set
		return result;
	vector<int> combination;
	getCombinations(candidates, target, 0, combination, result);
	return result;
}

void getCombinations(vector<int> &candidates, int target, size_t i,
		vector<int> combination, vector<vector<int> > &result) {
	if (target <= 0) {
		if (target == 0)
			if (find(result.begin(), result.end(), combination) == result.end())
				result.push_back(combination);
		return;
	}

	if (i == candidates.size()) // reach to end of array
		return;

	getCombinations(candidates, target, i + 1, combination, result); // result that does not include i
	if (target - candidates[i] >= 0) {
		combination.push_back(candidates[i]); // result that includes i
		getCombinations(candidates, target - candidates[i], i + 1, // go to next item
				combination, result);
	}
}

#endif /* COMBINATIONSUMII_H_ */
