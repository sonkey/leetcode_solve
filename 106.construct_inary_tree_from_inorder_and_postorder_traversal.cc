// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	return buildTree(inorder, postorder, inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

private:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, vector<int>::iterator in_begin, 
		vector<int>::iterator in_end, vector<int>::iterator pos_begin, vector<int>::iterator pos_end) {
		
		if (in_begin >= in_end || pos_begin >= pos_end) return nullptr;
		
		TreeNode *root = new TreeNode(*(pos_end - 1));
		auto pivot = find(in_begin, in_end, root->val);

		root->left = buildTree(inorder, postorder, in_begin, pivot, pos_begin, pos_begin + (pivot - in_begin));
		root->right = buildTree(inorder, postorder, pivot + 1, in_end, pos_begin + (pivot - in_begin), pos_end - 1);
		return root;
	}
};