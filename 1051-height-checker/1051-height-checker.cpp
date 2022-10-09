class Solution
{
    public:
        int heightChecker(vector<int> &heights)
        {

            vector<int> diffrence(heights.begin(), heights.end());
            sort(heights.begin(), heights.end());

            int cnt = 0;
            for (int i = 0; i < heights.size(); i++)
            {
                if (heights[i] != diffrence[i])
                {
                    cnt++;
                }
            }
            return cnt;
        }
};