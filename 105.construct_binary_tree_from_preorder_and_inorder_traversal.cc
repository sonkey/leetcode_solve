// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	return buildTree(preorder, inorder, preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

private:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, vector<int>::iterator pre_begin, 
		vector<int>::iterator pre_end, vector<int>::iterator in_begin, vector<int>::iterator in_end) {
		
		if (pre_begin >= pre_end || in_begin >= in_end) return nullptr;
		
		TreeNode *root = new TreeNode(*pre_begin);
		auto pivot = find(in_begin, in_end, root->val);

		root->left = buildTree(preorder, inorder, pre_begin + 1, pre_begin + 1 + (pivot - in_begin), in_begin, pivot);
		root->right = buildTree(preorder, inorder, pre_begin + 1 + (pivot - in_begin), pre_end, pivot + 1, in_end);
		return root;
	}
};