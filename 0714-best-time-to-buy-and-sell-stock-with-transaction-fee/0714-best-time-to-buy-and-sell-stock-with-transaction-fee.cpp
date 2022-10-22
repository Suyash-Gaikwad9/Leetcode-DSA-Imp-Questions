class Solution {
public:
    
    int solveSO(vector<int>& prices, int fee){
        int n = prices.size();
        //vector<vector<int>>dp(n+1, vector<int>(2, 0));
        
        vector<int>curr(2, 0);
        vector<int>next(2, 0);
        
        
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
        
                if(buy){
                    
                    int buyMove = -prices[index] + next[0];
                    int skipMove = 0 + next[1];
                    profit = max(buyMove, skipMove);
                }
                else{
                    int sellMove = +prices[index] + next[1] - fee;
                    int skipMove = 0 + next[0];
                    profit = max(sellMove, skipMove);
                }
                curr[buy] = profit;
                
            }
            next = curr;
        }
        return next[1];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
         return solveSO(prices, fee);
    }
};