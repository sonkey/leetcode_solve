/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        bool negative = false;

        if (x < 0) {
            x = -x;
            negative = true;
        }
        
        long long res = 0;
        while (x > 0) {
        	res += (x % 10);
        	res *= 10;
        	x /= 10;
        } 

        res = res / 10;
        
        if (res > numeric_limits<int>::max()) return 0;
        if (negative) res = -res;
        return res;
    }
};
