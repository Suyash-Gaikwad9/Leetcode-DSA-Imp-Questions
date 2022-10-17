//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve(int n, int a[], int curr, int prev){
        //base case
        if(curr == n){
            return 0;
        }
        
        //Include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
            take = 1 + solve(n, a, curr+1, curr);
        }
        
        //Exclude
        int notTake = 0 + solve(n, a, curr+1, prev);
        
        return max(take,notTake);
    }
    
    int solveMem(int n, int a[], int curr, int prev, vector<vector<int> >&dp){
        //base case
        if(curr == n){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        //Include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
            take = 1 + solveMem(n, a, curr+1, curr, dp);
        }
        
        //Exclude
        int notTake = 0 + solveMem(n, a, curr+1, prev, dp);
        
        dp[curr][prev+1] = max(take,notTake);
        return dp[curr][prev+1];
    }
    
    
    int solveTab(int n, int a[]){
        //step1
        vector<vector<int> >dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                
                //Include
                int take = 0;
                
                if(prev == -1 || a[curr] > a[prev]){
                    take = 1 + dp[curr+1][curr+1];
                }
                
                //Exclude
                int notTake = 0 + dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
    
    int solveSO(int n, int *a){
        
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                
                //Include
                int take = 0;
                
                if(prev == -1 || a[curr] > a[prev]){
                    take = 1 + nextRow[curr+1];
                }
                
                //Exclude
                int notTake = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    
    
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        //return solve(n, a, 0, -1);
        
        // vector<vector<int> >dp(n, vector<int>(n+1, -1));
        // return solveMem(n, a, 0, -1, dp);
        
        //return solveTab(n,a);
        return solveSO(n,a);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends