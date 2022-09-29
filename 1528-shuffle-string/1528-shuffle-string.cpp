class Solution
{
    public:
        string restoreString(string s, vector<int> &indices)
        {
            unordered_map<int, char> um;
            int n = indices.size();
            string ans = "";
            for (int i = 0; i < n; i++)
            {
                um[indices[i]] = s[i];
            }
            for (int i = 0; i < n; i++)
            {
                ans.push_back(um[i]);
            }
            return ans;
        }
};