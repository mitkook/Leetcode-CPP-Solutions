/*
 * BestTimetoBuyandSellStock.h
 *
 *  Created on: Dec 18, 2012
 *      Author: MiTKooK
 */

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 */

#ifndef BESTTIMETOBUYANDSELLSTOCK_H_
#define BESTTIMETOBUYANDSELLSTOCK_H_

// O(n)
int maxProfit(vector<int> &prices) {
	int min_i = 0;
	int max_profit = 0, profit = 0;
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < prices[min_i])
			min_i = i;
		profit = prices[i] - prices[min_i];
		if (profit > max_profit)
			max_profit = profit;
	}
	return max_profit;
}

#endif /* BESTTIMETOBUYANDSELLSTOCK_H_ */
