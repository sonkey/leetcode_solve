class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();

		int length = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[length]) {
				nums[++length] = nums[i];
			}
		} 

		return ++length; 
    }
};
