class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> tool;
        for (int i = 0; i < nums.size(); ++i) {
        	if (tool.count(nums[i])) 
        		return true;
        	else
        		tool.insert(nums[i]);
        }

        return false;
    }
};
