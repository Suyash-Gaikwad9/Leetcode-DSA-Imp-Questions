class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        int lastPos = n;
        for(int i = n; i >= 0; i--){
            if(i+nums[i] >= lastPos){
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};