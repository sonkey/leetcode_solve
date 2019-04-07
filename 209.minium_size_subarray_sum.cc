//https://leetcode-cn.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int ans = nums.size() + 1;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i - index + 1);
                sum -= nums[index++];   
            }
        }
        return (ans == nums.size() + 1) ? 0 : ans;
    }
};