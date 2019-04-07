//https://leetcode-cn.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxsize = 0;
        while (l < r) {
            maxsize = max(maxsize, min(height[l], height[r]) * (r - l));
            if (height[l] <= height[r]) l++;
            else r--;
        }
        return maxsize;
    }
};