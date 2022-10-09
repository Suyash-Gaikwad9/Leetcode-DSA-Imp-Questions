class Solution
{
    public:
        vector<int> sortArrayByParity(vector<int> &nums)
        {
            int i, j = 0;
            for (i = 0; i < nums.size(); i++)
            {
                if (nums[i] % 2 == 0)
                {
                    swap(nums[i], nums[j]);
                    j++;
                }
            }
            return nums;
        }
};