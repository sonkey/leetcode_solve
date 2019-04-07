/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	if (k > nums.size()) return 0;
    	return search(nums, 0, nums.size() - 1, k);
    }

private:
	int partition(vector<int>&nums, int l, int r) {
		int left = l + 1, right = r;
		while (left <= right) {
			if (nums[left] < nums[l] && nums[right] > nums[l]) {
				swap(nums[left++], nums[right--]);
			} 

			if (nums[left] >= nums[l]) left++;
			if (nums[right] <= nums[l]) right--;
		}
		swap(nums[right], nums[l]);
		return right;
	}

	int search(vector<int>&nums, int l, int r, int k) {
		int pos = partition(nums, l, r);
		if (pos == k -1) return nums[pos];
		if (pos > k - 1) return search(nums, l, pos - 1, k);
		else return search(nums, pos + 1, r, k);
	}
};