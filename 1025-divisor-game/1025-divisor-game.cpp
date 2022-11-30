class Solution {
public:
    bool divisorGame(int n) {
        vector<bool>dp(n+1);
        dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]=0;
            for(int j=i-1;j>=1;j--){
                if(i%j==0 && dp[i-j]==0){
                     dp[i]=1;
                }
            }
        }
        return dp[n];

    }
};