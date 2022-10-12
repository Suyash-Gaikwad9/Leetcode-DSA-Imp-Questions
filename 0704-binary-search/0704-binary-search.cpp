class Solution {
public:
    int binary_search(vector<int>& nums, int target){
        int start = 0; int end = nums.size()-1; int mid;
        
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid] < target){
                start = mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            mid = (start+end)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums,target);
    }
};