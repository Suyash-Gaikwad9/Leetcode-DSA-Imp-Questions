class Solution {
public:
    
    int solveTab(vector<int>& prices, int k){
        int n = prices.size();
        //vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        vector<vector<int>>curr(2, vector<int>(k+1,0));
        vector<vector<int>>next(2, vector<int>(k+1,0));
        
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= k; limit++){
                    
                    int profit = 0;
        
                    if(buy){
                        int buyMove = -prices[index] + next[0][limit];
                        int skipMove = 0 + next[1][limit];
                        profit = max(buyMove, skipMove);
                    }
                    else{
                        int sellMove = +prices[index] + next[1][limit-1];
                        int skipMove = 0 + next[0][limit];
                        profit = max(sellMove, skipMove);
                    }
                     curr[buy][limit] = profit;
                    
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(prices, k);
    }
};