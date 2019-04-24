// https://leetcode-cn.com/problems/jump-game/

//solution1 out of time limit
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        vector<bool> dp(nums.size()+1, false);
        dp[0] = true;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && nums[j] >= i - j) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[nums.size()-1];
    }
};

//solution2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        int target = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= target - i) {
                target = i;
            }
        }
        return target == 0;
    }
};