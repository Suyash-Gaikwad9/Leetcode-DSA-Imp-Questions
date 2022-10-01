class Solution {
public:
    //recursion
    int solve(vector<int>& cost, int n){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
    
    //DP Top-Down approch
    int solve2(vector<int>& cost, int n, vector<int>&dp){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        
        
        //step 3
        if(dp[n] != -1){
            return dp[n];
        }
        
        //step 2
        dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return dp[n];
    }
    
    
    //DP Bottom-Up approch
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // //this can be simplified
        // int ans = min(solve(cost, n-1), solve(cost, n-2));
        // return ans;
        
        
        int n = cost.size();
        //step 1
        vector<int>dp(n+1, -1);
        int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return ans;
        
    }
};