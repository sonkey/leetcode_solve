/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
 		if (m == 0) {
 			for (int idx = 0; idx != n; ++idx) {
 				nums1[idx] = nums2[idx];
 			}
 			return;
 		}

 		int i = m -1, j = n-1;
 		while ( i >=0 && j >= 0) {
 			if ( nums2[j] > nums1[i]) {
 				nums1[i + j + 1] = nums2[j];
 				j--; 
 			} else {
 				nums1[i + j + 1] = nums1[i];
 				i--;
 			}
 		}

 		if (i < 0 && j >= 0) {
 			for (int idx = 0; idx <= j; ++idx) {
 				nums1[idx] = nums2[idx];
 			}
 		}

 		return;
    }
};