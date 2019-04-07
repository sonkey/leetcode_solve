// https://leetcode-cn.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = dict.find(nums[i]);
            if (it == dict.end()) 
                dict[nums[i]] = i;
            else {
                if (i - it->second <= k) return true;
                else it->second = i;
            } 
        }
        return false;
    }
};