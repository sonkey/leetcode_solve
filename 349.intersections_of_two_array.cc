/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> res;
    	if (nums1.size() == 0 || nums2.size() == 0) return res;

    	set<int> help;
    	for (auto it = nums1.begin(); it != nums1.end(); ++it) {
    		help.insert(*it);
      	}

      	for (auto it = nums2.begin(); it != nums2.end(); ++it) {
      		if (help.count(*it) != 0) {
      			res.push_back(*it);
      			help.erase(*it);
      		} 
      	}

      	return res;
    }
};