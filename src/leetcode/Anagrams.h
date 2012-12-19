/*
 * Anagrams.h
 *
 *  Created on: Dec 18, 2012
 *      Author: MiTKooK
 */

/*
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */

#ifndef ANAGRAMS_H_
#define ANAGRAMS_H_

vector<string> anagrams(vector<string> &strs) {
	std::tr1::unordered_map < string, vector<string> > anagram_groups;
	string temp;
	for (int i = 0; i < strs.size(); i++) {
		temp = strs[i];
		sort(temp.begin(), temp.end());
		anagram_groups[temp].push_back(strs[i]); // if temp is not in the group, operator [] will create new one for it.
	}
	vector < string > result;
	std::tr1::unordered_map<string, vector<string> >::iterator it =
			anagram_groups.begin();
	while (it != anagram_groups.end()) {
		if (it->second.size() > 1)
			for (int i = 0; i < it->second.size(); i++)
				result.push_back(it->second[i]);
		it++;
	}
	return result;
}

#endif /* ANAGRAMS_H_ */
