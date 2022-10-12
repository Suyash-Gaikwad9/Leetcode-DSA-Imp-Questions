class Solution {
public:
    int solve(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low <= high){
            mid = low+(high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
        }
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};