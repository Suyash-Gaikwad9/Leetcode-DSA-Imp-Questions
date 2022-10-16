class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int time){
        //base case
        if(index == satisfaction.size())
            return 0;
        
        int include = satisfaction[index] * (time + 1) + solve(satisfaction, index+1, time+1);
    
        int exclude = 0 + solve(satisfaction, index+1, time);
        
        return max(include, exclude);
    }
    
    int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int> >&dp){
        //base case
        if(index == satisfaction.size())
            return 0;
        
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        
        int include = satisfaction[index] * (time + 1) + solveMem(satisfaction, index+1, time+1, dp);
    
        int exclude = 0 + solveMem(satisfaction, index+1, time, dp);
        
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }
    
    
    int maxSatisfaction(vector<int>& satisfaction) {
        // //sort the vector
        // sort(satisfaction.begin(), satisfaction.end());
        // return solve(satisfaction, 0, 0);
        
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
        return solveMem(satisfaction, 0, 0, dp);
        
        
        
    }
};