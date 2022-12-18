class Solution
{
    public:
        vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
        {
            int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
            int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
            int finalNeeded = (bobSum + aliceSum) / 2;
            unordered_map<int, int> mp;
            for (int i = 0; i < bobSizes.size(); i++)
            {
                mp[bobSizes[i]]++;
            }
            for (int i = 0; i < aliceSizes.size(); i++)
            {
                int other = finalNeeded - (aliceSum - aliceSizes[i]);
                if (other && mp.count(other))
                {
                    return {
                        aliceSizes[i],
                        other
                    };
                }
            }
            return { 0,
                0 };
        }
};