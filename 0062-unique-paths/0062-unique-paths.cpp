class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1) );
        
        for(int y = 1 ; y < m ; y++){
            for(int x = 1 ; x < n ; x++){
                
                // just follow the DP recurrence formula
                dp[y][x] = dp[y][x-1] + dp[y-1][x];
            }
        }
        return dp[m-1][n-1];
    }
};