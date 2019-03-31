/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        
        TreeNode* node = searchNode(root, key);
        if (node == nullptr) return root;
        if (node->left == nullptr && node->right == nullptr) {
            //delete node;
            node = nullptr;
            return root;
        }

        if (node->left == nullptr) {
            node->val = node->right->val;
            //delete node->right;
            node->right = nullptr;
            return root;
        }

        if (node->right == nullptr) {
            node->val = node->left->val;
            //delete node->left;
            node->left = nullptr;
            return root;
        }

        TreeNode *min_node = findMin(node->right);
        node->val = min_node->val;
        //delete min_node;
        min_node = nullptr;
        return root;
    }

private:
    TreeNode* findMin(TreeNode* root) {
        TreeNode *node = root;
        while (node) {
            root = node;
            node = node->left;
        }
        return root;
    }

    TreeNode* searchNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) return root;
        if (root->val > key) return searchNode(root->left, key);
        else return searchNode(root->right, key);
    }
};