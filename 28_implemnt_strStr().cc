/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
    	if (haystack.size() < needle.size()) return -1;
    	if (needle.size() == 0) return 0;

    	auto hsz = haystack.size();
    	auto nsz = needle.size();

    	for (int pos = 0; pos < hsz - nsz + 1; ++pos) {
    		int i = pos;
    		int j = 0;
    		while (j < nsz) {
    			if (haystack[i] != needle[j]) {
    				break;
    			} else {
    				i++;
    				j++;
    			}
    		}
    		if (j == nsz) {
    			return pos;
    		}
    	}
    	return -1;
    }
};