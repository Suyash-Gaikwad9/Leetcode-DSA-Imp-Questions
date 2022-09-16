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
private:
    TreeNode* solve(vector<int>nums, int s, int e){
        //base case
        if(s>e){
            return NULL;
        }
        int mid = (s + e)/2;
        
        TreeNode* temp = new TreeNode(nums[mid]);
        
        temp->left = solve(nums, s, mid-1);
        temp->right = solve(nums, mid+1, e);
        return temp;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(nums, 0, nums.size()-1);
    }
};