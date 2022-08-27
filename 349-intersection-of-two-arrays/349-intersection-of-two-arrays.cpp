class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto i:nums1)
        {
            for(auto j:nums2) if(i==j) s.insert(i);  
            // storing similar in set to remove duplicates
        }
        vector<int> ans(s.begin(),s.end());   
        // copying set values to vector as function return vector
        return ans;

    }
};