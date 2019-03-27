/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        auto iter = res.begin();
        bool flag = true;
        for (auto it = digits.crbegin(); it != digits.crend(); ++it) {
        	int num;
        	num = flag ? (*it + 1) : *it;
        	if (num == 10) {
        		iter = res.insert(iter, 0);
        		flag = true;
        	} else {
        		iter = res.insert(iter, num);
        		flag = false;
        	}
        }

        if (flag) res.insert(iter, 1);
        return res;
    }
}; 
