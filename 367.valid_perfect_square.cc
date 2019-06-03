// https://leetcode-cn.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        long long left = 2, right = num - 1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == num) return true;
            if (mid * mid > num) right = mid - 1;
            else left = mid + 1;
        } 
        return false;
    }
};