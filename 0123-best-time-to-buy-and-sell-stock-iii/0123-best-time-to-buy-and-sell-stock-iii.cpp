class Solution {
public:
//     int solve(int index, int buy, vector<int>& prices, int limit){
//         if(index == prices.size()){
//             return 0;
//         }
//         if(limit == 0){
//             return 0;
//         }
        
//         int profit = 0;
        
//         if(buy){
//             int buyMove = -prices[index] + solve(index+1, 0, prices, limit);
//             int skipMove = 0 + solve(index + 1, 1, prices, limit);
//             profit = max(buyMove, skipMove);
//         }
//         else{
//             int sellMove = +prices[index] + solve(index + 1, 1, prices, limit -1);
//             int skipMove = 0 + solve(index + 1, 0, prices, limit);
//             profit = max(sellMove, skipMove);
//         }
//     return profit;
//     }
    
    
    
    int solveMem(int index, int buy, vector<int>& prices, int limit, vector<vector<vector<int>>>&dp){
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0){
            return 0;
        }
        
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }
        
        int profit = 0;
        
        if(buy){
            int buyMove = -prices[index] + solveMem(index+1, 0, prices, limit, dp);
            int skipMove = 0 + solveMem(index + 1, 1, prices, limit, dp);
            profit = max(buyMove, skipMove);
        }
        else{
            int sellMove = +prices[index] + solveMem(index + 1, 1, prices, limit - 1, dp);
            int skipMove = 0 + solveMem(index + 1, 0, prices, limit, dp);
            profit = max(sellMove, skipMove);
        }
    return dp[index][buy][limit] = profit;
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1))); 
        return solveMem(0, 1, prices, 2, dp);
    }
};