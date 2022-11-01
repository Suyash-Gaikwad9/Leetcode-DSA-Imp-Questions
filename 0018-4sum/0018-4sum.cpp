class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            vector<vector < int>> ans;
            if (nums.empty())
                return ans;
            int n = nums.size();
            sort(nums.begin(), nums.end());

            for (int i = 0; i < n; i++)
            {
                long long int target3 = target - nums[i];

                for (int j = i + 1; j < n; j++)
                {
                    long long int target2 = target3 - nums[j];
                    int front = j + 1;
                    int back = n - 1;
                    while (front < back)
                    {
                        int two_sum = nums[front] + nums[back];
                        if (two_sum < target2)
                            front++;
                        else if (two_sum > target2)
                            back--;
                        else
                        {
                            vector<int> q(4, 0);
                            q[0] = nums[i];
                            q[1] = nums[j];
                            q[2] = nums[front];
                            q[3] = nums[back];
                            ans.push_back(q);

                            while (front < back && nums[front] == q[2])
                            {
                                ++front;
                            }
                            while (front < back && nums[back] == q[3])
                            {
                                --back;
                            }
                        }
                    }
                    while (j + 1 < n && nums[j + 1] == nums[j])
                    {
                        ++j;
                    }
                }
                while (i + 1 < n && nums[i + 1] == nums[i])
                {
                    ++i;
                }
            }
            return ans;
        }
};