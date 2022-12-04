class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sum = 0, cSum = 0;
        int n = nums.size();
        for(auto it: nums){
            sum+= it;
        }
        int mini = 1e9, ans = 0;
        for(int i = 0; i < n; i++){
            cSum += nums[i];
            int avg1 = cSum/(i+1);
            if(i == n-1){
                if(avg1 < mini){
                    return n-1;
                }
                else{
                    break;
                }
            }
            int avg2 = (sum-cSum)/(n-i-1);
            if(abs(avg1 - avg2) < mini){
                mini = abs(avg1 - avg2);
                ans = i;
            }
        }
        return ans;
    }
};