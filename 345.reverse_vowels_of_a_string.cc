/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。
*/

class Solution {
public:
    string reverseVowels(string s) {
        set<char> elem{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (elem.count(s[l]) == 0) {
                l++;
                continue;
            }

            if (elem.count(s[r]) == 0) {
                r--;
                continue;
            }

            if (elem.count(s[l]) != 0 && elem.count(s[r]) != 0) {
                swap(s[l], s[r]);
            }
            ++l;
            --r;
        }
        return s;
    }
};