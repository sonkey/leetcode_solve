/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间
*/

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
  	if (s1.size() > s2.size()) return false;

  	vector<int> res1(26);
  	vector<int> res2(26);

  	for (int i = 0; i < s1.size(); ++i) {
  		res1[s1[i] - 'a']++;
  		res2[s2[i] - 'a']++;
  	}

  	if (res1 == res2) return true;

  	for (int i = s1.size(), j = 0; i < s2.size(); ++i, ++j) {
  		res2[s2[i] - 'a']++;
  		res2[s2[j] - 'a']--;
  		if (res1 == res2) return true;
  	}

  	return false;
  }
};