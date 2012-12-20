/*
 * ClimbingStairs.h
 *
 *  Created on: Dec 19, 2012
 *      Author: MiTKooK
 */

/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

#ifndef CLIMBINGSTAIRS_H_
#define CLIMBINGSTAIRS_H_

// idea: fibonacci numbers
int climbStairs(int n) {
	if (n <= 2)
		return n;
	int a = 1; //1 way to climb stair of length 1
	int b = 2; //2 ways (1,1 and 2) to climb stairs
	int c;
	for (int i = 2; i < n; i++) {
		c = a + b; // last move could be (1+1) + through a, or 2 + through b, so total will be (a + b) ways
		a = b;
		b = c;
	}
	return c;
}

#endif /* CLIMBINGSTAIRS_H_ */
