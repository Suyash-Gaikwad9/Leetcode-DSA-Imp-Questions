/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
int maxDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	else
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

public:
    bool isBalanced(TreeNode* root) {
	if(root == NULL)
		return true;
		
	//balanced binary tree condition
	if(abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
		return false;
		
	//checking for left and right child of every node
	if(!isBalanced(root->left) || !isBalanced(root->right))
		return false;
	return true;
}
    
};