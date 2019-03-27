/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    return search(nums, target, 0, nums.size() - 1);
  }

private:
  int search(vector<int>& nums, int target, int left, int right) {
    if (right < left) return -1;

    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;

    int res;
    if (nums[left] < nums[mid]) {
      res = bsearch(nums, target, left, mid - 1);
      if (res != -1) return res;
    } else {
      res = search(nums, target, left, mid - 1);
      if (res != -1) return res;
    }

    if (nums[mid] < nums[right]) {
      res = bsearch(nums, target, mid + 1, right);
      if (res != -1) return res;
    } else {
      res = search(nums, target, mid + 1, right);
      if (res != -1) return res;
    }

    return -1;
  }


  int bsearch(vector<int>& nums, int target, int left, int right) {
    if (left > right) return -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      else if (nums[mid] > target) right = mid - 1;
      else left = mid + 1;
    }
    return -1;
  }
};