/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        int min_sz = strs[0].size();
        for (auto str : strs) {
            if (str.size() < min_sz)
                min_sz = str.size();
        }

        if (min_sz == 0) return "";

        string res;
        int index = 0;
        bool flag = true;
        while (index < min_sz) {
            char ch = strs[0][index];
            for (auto str : strs) {
                if (str[index] != ch) {
                    flag = false;
                    break;
                }
            }
            if (flag) { 
                res.push_back(ch);
                index++;
            } else {
                break;
            }
        }

        return res;
    }
};
