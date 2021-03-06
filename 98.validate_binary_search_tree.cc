/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value is 5 but its right child's value is 4.

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。根节点的值为 5 ，但是其右子节点值为 4 。
*/

//solution1
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        if (!left) return false;

        if (!st.empty()) {
            if (root->val > st.top()) 
                st.push(root->val);
            else 
                return false;
        } else 
            st.push(root->val);

        bool right = isValidBST(root->right);
        return right;
    }

private:
    stack<int> st;
};

//solution2
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
private:
    bool isValidBST(TreeNode* node, long minv, long maxv) {
        if (node == nullptr) return true;
        if (node->val >= maxv || node->val <= minv) return false;
        return isValidBST(node->left, minv, node->val) && isValidBST(node->right, node->val, maxv);
    }
};

