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
    
    bool match(TreeNode* left, TreeNode* right){
        if(left != NULL && right != NULL){
            bool a = match(left -> left, right->right);
            bool b = match(left->right, right->left);
            
            if((left -> val == right -> val)&& a && b){
                return true;
            }
            else{
                return false;
            }
        }
            if(left == NULL && right == NULL){
                return true;
            }
            else{
                return false;
            }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return match(root->left, root->right);
    }
};