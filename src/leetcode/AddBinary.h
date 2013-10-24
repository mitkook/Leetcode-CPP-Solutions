/*
 * AddBinary.h
 *
 *  Created on: Dec 18, 2012
 *      Author: MiTKooK
 */

/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

#ifndef ADDBINARY_H_
#define ADDBINARY_H_

using namespace std;

/*
 *
 * template <class BidirectionalIterator>
 * void reverse ( BidirectionalIterator first, BidirectionalIterator last) {
 * 		while ((first!=last)&&(first!=--last))
 * 		swap (*first++,*last);
 * }
 */

// c = a + b
string addBinary(string a, string b) {
	reverse(a.begin(), a.end()); // #include <algorithm>
	reverse(b.begin(), b.end());
	string::iterator i = a.begin();
	string::iterator j = b.begin();
	string c;
	int carry = 0;
	int a_value, b_value, sum;
	while (i != a.end() || j != b.end()) {
		if (i != a.end())
			a_value = *(i++) - '0';
		else
			a_value = 0;

		if (j != b.end())
			b_value = *(j++) - '0';
		else
			b_value = 0;

		sum = a_value + b_value + carry;
		c.push_back('0' + (sum % 2));
		carry = sum / 2;
	}
	if (carry == 1)
		c.push_back('1');
	reverse(c.begin(), c.end());
	return c;
}

#endif /* ADDBINARY_H_ */
