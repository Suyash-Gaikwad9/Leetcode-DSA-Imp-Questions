class Solution {
public:
    int maxJump(vector<int>& stones) {
        unordered_map<int, int>v;
        int mx = -1;
        for(int i = 0; i < (int)stones.size()-2; i+=2){
            v[i+2] = 1;
            mx = max(mx, abs(stones[i] - stones[i+2]));
        }
        vector<int>alt;
        for(int i = 0; i < stones.size(); i++){
            if(!v[i])
                alt.push_back(i);
        }
        for(int i = 0; i<alt.size()-1; i++){
            mx = max(mx, abs(stones[alt[i]] - stones[alt[i+1]]));
        }
        return mx;
    }
};