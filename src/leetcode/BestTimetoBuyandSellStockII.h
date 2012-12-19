/*
 * BestTimetoBuyandSellStockII.h
 *
 *  Created on: Dec 18, 2012
 *      Author: MiTKooK
 */

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
 * However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#ifndef BESTTIMETOBUYANDSELLSTOCKII_H_
#define BESTTIMETOBUYANDSELLSTOCKII_H_

int maxProfit(vector<int> &prices) {
	if (prices.size() < 2)
		return 0;
	int max_profit = 0;
	for (int i = 1; i < prices.size(); i++)
		if (prices[i] > prices[i - 1])
			max_profit += (prices[i] - prices[i - 1]);
	return max_profit;
}

#endif /* BESTTIMETOBUYANDSELLSTOCKII_H_ */
