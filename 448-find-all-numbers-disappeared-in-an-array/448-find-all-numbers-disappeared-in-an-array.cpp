class Solution
{
    public:
        vector<int> findDisappearedNumbers(vector<int> &nums)
        {
            int size = nums.size();
            vector<int> ans;
            vector<int> count(size + 1, 0);
            for (int i = 1; i <= size; i++)
            {
                count[nums[i - 1]]++;
            }

            for (int i = 1; i <= size; i++)
            {
                if (count[i] == 0)
                    ans.push_back(i);
            }
            return ans;
        }
};