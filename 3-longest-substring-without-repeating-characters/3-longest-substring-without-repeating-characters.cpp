class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256, -1);
        int n = s.size();
        int left = 0;
        int right = 0;
        int length = 0;
        while(right < n){
            if(mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left);
            
            mpp[s[right]] = right;
            
            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};