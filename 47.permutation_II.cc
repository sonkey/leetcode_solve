// https://leetcode-cn.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> vec;
        vector<bool> used(nums.size(), false);
        recursive(res, vec, used, nums, 0);
        return res;
    }

private:
    void recursive(vector<vector<int>>& res, vector<int>& vec, vector<bool>& used, vector<int>& nums, int n) {
        if (n == nums.size()) {
            res.push_back(vec);
            return;
        }

        int last = nums[0] - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (nums[i] == last) continue;

            last = nums[i];
            used[i] = true;
            vec.push_back(nums[i]);
            recursive(res, vec, used, nums, n+1);
            used[i] = false;
            vec.pop_back();
        }
    }
};