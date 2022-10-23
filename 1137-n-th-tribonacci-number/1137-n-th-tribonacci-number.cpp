class Solution {
public:
    int solve(int n){
        int dp[n+1];
        
        if(n <= 1){
            return n;
        }
        else if(n == 0){
            return 0;
        }
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
    int tribonacci(int n) {
        return solve(n);
    }
};