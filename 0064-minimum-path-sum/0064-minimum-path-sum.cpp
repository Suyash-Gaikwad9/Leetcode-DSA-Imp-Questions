class Solution
{
    public:
        int minCost(vector<vector < int>> &cost, int m, int n, vector< vector< int>> &dp)
        {
            if (n < 0 || m < 0)
                return INT_MAX;
            else if (m == 0 && n == 0)
                return cost[m][n];
            if (dp[m][n] != -1)
                return dp[m][n];
            int r = cost[m][n] + min(minCost(cost, m - 1, n, dp), minCost(cost, m, n - 1, dp));
            dp[m][n] = r;
            return r;
        }

    int minPathSum(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector < int>> dp(m, vector<int> (n, -1));
        return minCost(grid, m - 1, n - 1, dp);
    }
};