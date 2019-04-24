//https://leetcode-cn.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used{false, false, false, false, false, false};
        vector<vector<int>> res;
        vector<int> vec;
        recursive(res, used, nums, vec, 0);
        return res;
    }

private:
    void recursive(vector<vector<int>>& res, vector<bool>& used, vector<int>& nums, vector<int>& vec, int n) {
        if (n == nums.size()) {
            res.push_back(vec);
            return;
        } 

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            vec.push_back(nums[i]);
            used[i] = true;
            recursive(res, used, nums, vec, n+1);
            used[i] = false;
            vec.pop_back();
        }
    }
};