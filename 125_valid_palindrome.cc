/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/

class Solution {
public:
    bool isPalindrome(string s) {
        auto bit = s.begin();
        auto eit = s.end() - 1;
        while (bit < eit) {
        	if (!isdigit(*bit) && !isalpha(*bit)) {
        		++bit;
        		continue;
        	}
        	if (!isdigit(*eit) && !isalpha(*eit)) {
        		--eit;
        		continue;
        	}

        	if (isdigit(*bit) && isdigit(*eit)) {
        		if (*eit == *bit) {
        			bit++;
        			eit--;
                    continue;
        		}
        	}

        	if (isalpha(*bit) && isalpha(*eit)) {
        		if (equal(*bit, *eit)) {
        			bit++;
        			eit--;
        			continue;
        		}
        	}

        	return false;
        }
        return true;
    }

private:
	bool equal(char a, char b) {
		if (a == b) return true;
		if ((a^32) == b || a == (b^32)) return true;
		return false;
	}
};
