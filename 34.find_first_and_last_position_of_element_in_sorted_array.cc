/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res;
      if (nums.size() == 0) return {-1,-1};
      if (nums.size() == 1 && nums[0] == target) return {0,0};
      if (nums.size() == 1 && nums[0] != target) return {-1,-1}; 
      
      int left = 0, right = nums.size();
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) 
          left = mid + 1;
        else 
          right = mid;
      }
      nums[left] == target ? res.push_back(left) : res.push_back(-1);
      if (res[0] == -1) {
        res.push_back(-1);
        return res;
      }

      left = 0, right = nums.size() - 1;
      while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) 
          right = mid;
        else 
          left = mid;
      }
      nums[right] == target ? res.push_back(right) : res.push_back(left);

      return res;
    }
};