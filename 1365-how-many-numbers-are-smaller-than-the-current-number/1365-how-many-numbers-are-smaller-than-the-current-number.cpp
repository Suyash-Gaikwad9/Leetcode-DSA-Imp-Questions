class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        map<int, int>m;
        vector<int>v = nums;
        
        sort(v.begin(), v.end());
        for(int i = n-1; i >= 0; i--){
            m[v[i]] = i;
        }
        
        for(int i = 0; i<n; i++){
            nums[i] = m[nums[i]];
        }
        return nums;
    }
};