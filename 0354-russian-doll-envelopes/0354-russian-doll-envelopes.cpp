class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    
    int solveOptimal(int n, vector<vector<int>>& e){
           
        sort(e.begin(), e.end(), comp);
        
        vector<int>ans;
        ans.push_back(e[0][1]);
        
        for(int i = 0; i < n; i++){
            auto it = lower_bound(ans.begin(), ans.end(), e[i][1]);
            if(it==ans.end()){ans.push_back(e[i][1]);}
            else{
                *it = e[i][1];
            }
        }
        return ans.size();

        
    }
    
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        return solveOptimal(n, envelopes);
    }
};