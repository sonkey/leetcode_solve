/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

//solution1

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        if (!left) return false;

        if (!st.empty()) {
            bool mid = root->val > st.top();
            if (mid) st.push(root->val);
            else return false;
        } else st.push(root->val);

        bool right = isValidBST(root->right);
        return right;
    }

private:
    stack<int> st;
};

