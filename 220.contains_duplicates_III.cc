// https://leetcode-cn.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> dup;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = dup.lower_bound(nums[i]);
            if (it != dup.end() && long(long(*it) - long(nums[i])) <= t)
                return true;
            if (it != dup.begin() && long(long(nums[i]) - long(*(--it))) <= t)
                return true;
            dup.insert(nums[i]);
            if (dup.size() > k) dup.erase(nums[i - k]);
        }
        return false;
    }
};