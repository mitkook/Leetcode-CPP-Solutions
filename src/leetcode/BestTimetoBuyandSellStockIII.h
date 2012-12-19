/*
 * BestTimetoBuyandSellStockIII.h
 *
 *  Created on: Dec 18, 2012
 *      Author: MiTKooK
 */

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#ifndef BESTTIMETOBUYANDSELLSTOCKIII_H_
#define BESTTIMETOBUYANDSELLSTOCKIII_H_

/*
 * idea:
 * use an array to record max_profit for the first transaction (from 0 to time i)
 * use another array to record max_profit for the second transaction (from time i to the end)
 * iterate two arrays to get the max profit for the two transactions.
 *
 * O(n)
 */
int maxProfit(vector<int> &prices) {
	int N = prices.size();
	if (N < 2)
		return 0;

	int min_val = prices[0];
	vector<int> left(N, 0);
	for (int i = 1; i < N; ++i) {
		if (prices[i] < min_val)
			min_val = prices[i];
		left[i] = max(left[i - 1], prices[i] - min_val);
	}

	int max_val = prices[N - 1];
	vector<int> right(N, 0);
	for (int i = N - 2; i >= 0; --i) {
		if (prices[i] > max_val)
			max_val = prices[i];
		right[i] = max(right[i + 1], max_val - prices[i]);
	}

	int max_profit = 0;
	for (int i = 0; i < N; ++i)
		max_profit = max(max_profit, left[i] + right[i]);
	return max_profit;
}

#endif /* BESTTIMETOBUYANDSELLSTOCKIII_H_ */
