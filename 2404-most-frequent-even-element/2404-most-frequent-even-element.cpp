class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>cnt;
            
            for(int i:nums){
                if(i%2==0)
                   cnt[i]++;    
            }
            
            int ans=-1 ,frequency=INT_MIN; 
            
            for(auto i: cnt){
                    if(i.second>frequency){
                            ans=i.first, frequency=i.second;
                    }
            }
            return ans;
    }
};