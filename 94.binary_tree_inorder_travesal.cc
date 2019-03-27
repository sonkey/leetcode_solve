/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      if (!root) return res;

      stack<TreeNode*> st;
      //st.push(root);
      TreeNode* cur = root;

      while (cur || !st.empty()) {
        if (cur) {
          st.push(cur);
          cur = cur->left;
        } else {
          cur = st.top();
          res.push_back(cur->val);
          cur = cur->right;
          st.pop();
        }
      }

      return res;
    } 
};