class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return n;
        
        int i = 2;
        int j=0;
        for( j = i; j < nums.size(); j++){
            if(nums[j] != nums[i-2]){
                nums[i++]=nums[j];
            }
        }
        return i;
    }
};