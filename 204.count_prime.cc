/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        int num[n];
        for (int i = 0; i < n; ++i) num[i] = -1;
        for (int i = 2; i < n; ++i) {
            if (num[i] == -1) {
                int mul = 2;
                while (mul*i < n) {
                    num[mul*i] = 1;
                    mul++;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (num[i] == -1) count++;
        }
        return count;
    }
};