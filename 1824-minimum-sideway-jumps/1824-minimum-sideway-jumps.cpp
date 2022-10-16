class Solution {
public:
    int solve(vector<int>& obstacles, int currLane, int currPos){
        //base case
        int n = obstacles.size()-1;
        
        if(currPos == n)
            return 0;
        
        if(obstacles[currPos + 1] != currLane){
            return solve(obstacles, currLane, currPos+1);
        }
        else{
            //sideways jumps
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currLane != i && obstacles[currPos]!=i)
                    ans = min(ans, 1+ solve(obstacles, i, currPos));
            }
            return ans;
        }
    }
    
    
    int solveMem(vector<int>& obstacles, int currLane,int currPos,vector<vector<int> >& dp){
        //base case
        int n = obstacles.size()-1;
        
        if(currPos == n)
            return 0;
        
        if(dp[currLane][currPos] != -1){
            return dp[currLane][currPos];
        }
        
        if(obstacles[currPos + 1] != currLane){
            return solveMem(obstacles, currLane, currPos+1, dp);
        }
        else{
            //sideways jumps
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currLane != i && obstacles[currPos]!=i)
                    ans = min(ans, 1+ solveMem(obstacles, i, currPos, dp));
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }
    
    
    int solveTab(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int> > dp(4, vector<int>(obstacles.size(), 1e9));
        
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        
        
        for(int pos = n-1; pos >= 0; pos--){
            for(int lane = 1; lane <= 3; lane++){
                
        if(obstacles[pos + 1] != lane){
            dp[lane][pos] = dp[lane][pos+1];
        }
        else{
            //sideways jumps
            int ans = 1e9;
            for(int i = 1; i <= 3; i++){
                if(lane != i && obstacles[pos]!=i)
                    ans = min(ans, 1+ dp[i][pos+1]);
            }
            dp[lane][pos] = ans;
        }
                
                
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }
    
    
    
    int minSideJumps(vector<int>& obstacles) {
        //return solve(obstacles, 2, 0);
        // int n = obstacles.size()-1;
        // vector<vector<int> >dp(4, vector<int>(obstacles.size(), -1));
        // return solveMem(obstacles, 2, 0, dp);
        
        return solveTab(obstacles);
        
        
        
        
        
    }
};