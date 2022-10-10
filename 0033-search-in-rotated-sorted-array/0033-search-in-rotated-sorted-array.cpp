class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start <= end){
            mid = (start+end)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[start] <= nums[mid]){
                
                if(target <= nums[mid] && target >= nums[start]){
                    end = mid;
                }
                else{
                    start = mid + 1;
                }
                
            }
            else if(target >= nums[mid] && target <= nums[end]){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return -1;
    }
};