class Solution {
public:
    
//     int solveTab(vector<int>& prices, int k){
//         int n = prices.size();
//         //vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
//         vector<vector<int>>curr(2, vector<int>(k+1,0));
//         vector<vector<int>>next(2, vector<int>(k+1,0));
        
//         for(int index = n-1; index >= 0; index--){
//             for(int buy = 0; buy <= 1; buy++){
//                 for(int limit = 1; limit <= k; limit++){
                    
//                     int profit = 0;
        
//                     if(buy){
//                         int buyMove = -prices[index] + next[0][limit];
//                         int skipMove = 0 + next[1][limit];
//                         profit = max(buyMove, skipMove);
//                     }
//                     else{
//                         int sellMove = +prices[index] + next[1][limit-1];
//                         int skipMove = 0 + next[0][limit];
//                         profit = max(sellMove, skipMove);
//                     }
//                      curr[buy][limit] = profit;
                    
//                 }
//             }
//             next = curr;
//         }
//         return next[1][k];
//     }
    
    int solve(int index, int operationNo, int k, vector<int>& prices){
        if(index == prices.size()){
            return 0;
        }
        if(operationNo == 2*k){
            return 0;
        }
        int profit = 0;
        if(operationNo % 2 == 0){
            //buy allowd
            int buyMove = -prices[index] + solve(index+1, operationNo + 1, k, prices);
            int skipMove = 0 + solve(index+1, operationNo, k, prices);
            profit = max(buyMove, skipMove);
        }
        else{
            int sellMove = +prices[index] + solve(index+1, operationNo+1, k, prices);
            int skipMove = 0 + solve(index+1, operationNo, k, prices);
            profit = max(sellMove, skipMove);
        }
        return profit;
    }
    
    
    
    int solveMem(int index, int operationNo, int k, 
                 vector<int>& prices, vector<vector<int>>&dp){
        if(index == prices.size()){
            return 0;
        }
        if(operationNo == 2*k){
            return 0;
        }
        
        if(dp[index][operationNo] != -1){
            return dp[index][operationNo];
        }
        
        
        int profit = 0;
        if(operationNo % 2 == 0){
            //buy allowd
            int buyMove = -prices[index] + solveMem(index+1, operationNo + 1, k, prices, dp);
            int skipMove = 0 + solveMem(index+1, operationNo, k, prices, dp);
            profit = max(buyMove, skipMove);
        }
        else{
            int sellMove = +prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
            int skipMove = 0 + solveMem(index+1, operationNo, k, prices, dp);
            profit = max(sellMove, skipMove);
        }
        return dp[index][operationNo] = profit;
    }
    
    
    
    int maxProfit(int k, vector<int>& prices) {
        //return solveTab(prices, k);
        //return solve(0, 0, k, prices);
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2*k, -1));
        return solveMem(0, 0, k, prices, dp);
    }
};