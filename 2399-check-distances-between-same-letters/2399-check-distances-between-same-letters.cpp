class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<int, int> mp;
        int n = s.length();
        for(int i = 0;i < n; i++){
            if(mp[s[i]] == 0){
                mp[s[i]] = i+1;
            }else{
                if(distance[s[i] - 'a'] != (i-mp[s[i]])){
                    return false;
                }
            }
        }
        return true;
    }
};