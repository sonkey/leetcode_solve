/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
  	vector<vector<int>> res;
  	if (nums.size() < 4) return res;

  	sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        //if (nums[i] > target) break;
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int target1 = target - nums[i];
        for (int j = i + 1; j < nums.size(); ++j) {
            //if (nums[j] > target1) break;
            if (j > i + 1 && nums[j] == nums[j-1]) continue;

            int begin = j + 1;
            int end = nums.size() - 1;
            int target2 = target1 - nums[j];
            while (begin < end) {
                if (nums[begin] + nums[end] > target2) end--;
                else if (nums[begin] + nums[end] < target2) begin++;
                else {
                    res.push_back({nums[i], nums[j], nums[begin], nums[end]});
                    while (begin < end && nums[begin] == nums[begin + 1]) begin++;
                    while (begin < end && nums[end] == nums[end - 1]) end--;
                    begin++;
                    end--;
                }
            }
        }
    }

 		return res;
	}
};