/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[right] < nums[mid])
          left = mid + 1;
        else 
          right = mid;
      }
      return nums[left];
    }
};