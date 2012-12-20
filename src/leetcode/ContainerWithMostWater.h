/*
 * ContainerWithMostWater.h
 *
 *  Created on: Dec 20, 2012
 *      Author: MiTKooK
 */

/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */

#ifndef CONTAINERWITHMOSTWATER_H_
#define CONTAINERWITHMOSTWATER_H_

int maxArea(vector<int> &height) {
	int left = 0;
	int right = height.size() - 1;
	int max = 0, h = 0, result = 0;
	while (left < right) {
		h = (height[left] < height[right]) ? height[left] : height[right]; // choose the lower tower
		result = h * (right - left); // current area
		if (result > max)
			max = result;
		if (height[left] <= height[right]) {
			left++;
			while (height[left] < h && left < right)
				left++;
		} else {
			right--;
			while (height[right] < h && left < right)
				right--;
		}
	}
	return max;
}

#endif /* CONTAINERWITHMOSTWATER_H_ */
