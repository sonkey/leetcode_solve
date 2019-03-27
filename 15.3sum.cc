/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) return res;
    sort(nums.begin(), nums.end());

    for (int pivot = 0; pivot < nums.size(); ++pivot) {
      if (nums[pivot] > 0) break;
      if (pivot > 0 && nums[pivot] == nums[pivot-1]) continue;
      int target = 0 - nums[pivot];

      int i = pivot + 1;
      int j = nums.size() - 1;
      while (i < j) {
        if (nums[i] + nums[j] > target) j--;
        else if (nums[i] + nums[j] < target) i++;
        else {
          res.push_back({nums[pivot], nums[i], nums[j]});
          while (i < j && nums[i] == nums[i+1]) i++;
          while (i < j && nums[j] == nums[j-1]) j--;
          i++;
          j--;
        }
      }
    }
    return res;
  }
};