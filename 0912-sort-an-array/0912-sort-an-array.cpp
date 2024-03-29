class Solution
{
    public:
        void merge(vector<int> &nums, int low, int mid, int high)
        {
            vector<int> temp(high - low + 1);
            int i = low, j = mid + 1, k = 0;
            while (i <= mid && j <= high)
            {
                if (nums[i] <= nums[j])
                {
                    temp[k++] = nums[i++];
                }
                else
                {
                    temp[k++] = nums[j++];
                }
            }
            while(i <= mid){
                temp[k++] = nums[i++];
            }
            while(j <= high){
                temp[k++] = nums[j++];
            }
            for(int p = 0; p < k; p++){
                nums[low + p] = temp[p];
            }
        }
    void merge_sort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
        {
            return;
        }
        int mid = (low + high) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};