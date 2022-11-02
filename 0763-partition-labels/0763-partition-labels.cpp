class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        // filling impact of character's
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            m[ch] = i;
        }
        // making of result
        vector<int> ans;
        int prev = -1;
        int maxi = 0;
        
        for(int i = 0; i < s.size(); i++){
            maxi = max(maxi, m[s[i]]);
            if(maxi == i){
                // partition time
                ans.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return ans;
    }
};