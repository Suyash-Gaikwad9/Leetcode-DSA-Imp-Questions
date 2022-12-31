class Solution
{
    private:
    int startx;
    int starty;
    int endx;
    int endy;
    int ans = 0;
    int pathse;
    int m;
    int n;
    public:
        void dfs(vector<vector<int>> grid, int i, int j, int path)
        {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
            {
                return;
            }
            if (i == endx && j == endy && path == pathse)
            {
                ans++;
                return;
            }
            grid[i][j] = -1;
            dfs(grid, i, j + 1, path + 1);
            dfs(grid, i + 1, j, path + 1);
            dfs(grid, i, j - 1, path + 1);
            dfs(grid, i - 1, j, path + 1);
        }
    int uniquePathsIII(vector<vector < int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        pathse = m * n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    startx = i;
                    starty = j;
                }
                else if (grid[i][j] == 2)
                {
                    endx = i;
                    endy = j;
                }
                else if (grid[i][j] == -1)
                {
                    pathse--;
                }
            }
        }
        dfs(grid, startx, starty, 1);
        return ans;
    }
};