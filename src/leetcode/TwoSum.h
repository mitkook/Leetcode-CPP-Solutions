/*
 * TwoSum.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#ifndef TWOSUM_H_
#define TWOSUM_H_

using namespace std;

// O(nlogn) method
vector<int> twoSum(vector<int> &numbers, int target) {
	int N = numbers.size();
	vector<int> copy(numbers.begin(), numbers.end());
	sort(copy.begin(), copy.end());
	int i = 0;
	int j = N - 1;
	int sum;
	while (i < j) {
		sum = copy[i] + copy[j];
		if (sum > target)
			j--;
		else if (sum < target)
			i++;
		else
			// find a pair
			break;
	}
	vector<int> result;
	// locate the pair in original array
	for (int k = 0; k < N; k++) {
		if (copy[i] == numbers[k]) {
			result.push_back(k + 1);
			break;
		}
	}
	for (int k = 0; k < N; k++) {
		if (copy[j] == numbers[k] && (k + 1) != result[0]) {
			result.push_back(k + 1);
			break;
		}
	}
	if (result[0] > result[1])
		swap(result[0], result[1]);
	return result;
}

// O(n) method, using hash table
vector<int> twoSum2(vector<int> &numbers, int target) {
	std::tr1::unordered_map<int, int> hash;
	int N = numbers.size();
	int i;
	for (i = 0; i < N; i++) {
		hash[(target - numbers[i])] = i;
	}
	for (i = 0; i < N; i++) {
		if (hash.find(numbers[i]) != hash.end())
			if (hash[numbers[i]] != i)
				break;
	}

	vector<int> result;
	result.push_back(i+1); // index started from 1
	result.push_back(hash[numbers[i]]+1);
	if (result[0] > result[1])
		swap(result[0], result[1]);
	return result;
}

#endif /* TWOSUM_H_ */
