/*
 * Combinations.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 * [
 *	[2,4],
 *	[3,4],
 *	[2,3],
 *	[1,2],
 *	[1,3],
 *	[1,4],
 * ]
 */

#ifndef COMBINATIONS_H_
#define COMBINATIONS_H_

using namespace std;

vector<vector<int> > combine(int n, int k) {
	vector < vector<int> > result;
	vector<int> combination;
	getCombinations(n, k, 1, combination, result);
	return result;
}

void getCombinations(int n, int k, int i, vector<int> combination, vector<vector<
		int> > &result) {
	if (combination.size() == k) {
		result.push_back(combination);
		return;
	}

	if (i > n)
		return;

	getCombinations(n, k, i + 1, combination, result);
	combination.push_back(i);
	getCombinations(n, k, i + 1, combination, result);
}

#endif /* COMBINATIONS_H_ */
