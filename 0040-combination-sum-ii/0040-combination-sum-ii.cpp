class Solution {
public:
    void findComb(int index, int target, vector<int>&arr, vector<vector<int> >&ans, vector<int>dp){
        if(target == 0){
            ans.push_back(dp);
            return;
        }
        for(int i = index; i < arr.size(); i++){
            if(i > index && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i] > target){
                break;
            }
            dp.push_back(arr[i]);
            findComb(i+1, target - arr[i], arr, ans, dp);
            dp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int> >ans;
        vector<int>ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};