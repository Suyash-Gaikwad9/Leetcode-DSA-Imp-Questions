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
public:
    int solve(TreeNode* root, int Cmin, int Cmax){
        
        if(!root){
            return Cmax-Cmin;
        }
        Cmax = max(root->val, Cmax);
        Cmin = min(root->val, Cmin);
        int leftP = solve(root->left, Cmin, Cmax);
        int rightP = solve(root->right, Cmin, Cmax);
        return max(leftP, rightP);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        return solve(root, root->val, root->val);
    }
};