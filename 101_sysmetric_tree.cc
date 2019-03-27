/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/

//solution1
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
    bool isSymmetric(TreeNode* root) {
      if (root == NULL) return true;
      stack<TreeNode*> lst;
      stack<TreeNode*> rst;
      lst.push(root->left);
      rst.push(root->right);
      while (!lst.empty() && !rst.empty()) {
        if (lst.top() == NULL && rst.top() != NULL) return false;
        if (rst.top() == NULL && lst.top() != NULL) return false;
        if (lst.top() == NULL && rst.top() == NULL) {
          lst.pop();
          rst.pop();
          continue;
        }
        TreeNode* l = lst.top();
        TreeNode* r = rst.top();
        if (l->val != r->val) return false;
        lst.pop();
        rst.pop();
        lst.push(l->left);
        lst.push(l->right);
        rst.push(r->right);
        rst.push(r->left);
      }
      return lst.empty() && rst.empty();
    }
};

//solution2
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
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return recursive(root->left, root->right);
  }

private:
  bool recursive(TreeNode* left, TreeNode *right) {
    if (left && !right) return false;
    if (!left && right) return false;
    if (!left && !right) return true;
    if (left->val != right->val) return false;
    return recursive(left->left, right->right) && recursive(left->right, right->left);
  }
};