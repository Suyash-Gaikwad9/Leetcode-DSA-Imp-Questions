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
    bool post(TreeNode* p, TreeNode* q){
        //base case
        if(p == NULL && q == NULL){
            return true;
        }
        
        if(p == NULL || q == NULL){
            return false;
        }
        return (p->val == q->val) && post(p->left, q->left) && post(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return post(p, q);
    }
};