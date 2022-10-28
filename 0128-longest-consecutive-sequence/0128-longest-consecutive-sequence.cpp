class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(),nums.end());
        
        int longestStreak = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(hashSet.find(nums[i] - 1)!=hashSet.end())
                continue;
            
            else
            {
                int count = 0;
                int current_element = nums[i];
                
                while(hashSet.find(current_element) != hashSet.end())
                {
                    count++;
                    current_element++;
                }
                
                longestStreak = max(longestStreak,count);
            }
        }
        
        return longestStreak;
    }
};


// unordered_set<int> hashSet(nums.begin(),nums.end());
        
//         int longestStreak = 0;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(hashSet.find(nums[i] - 1)!=hashSet.end())
//                 continue;
            
//             else
//             {
//                 int count = 0;
//                 int current_element = nums[i];
                
//                 while(hashSet.find(current_element) != hashSet.end())
//                 {
//                     count++;
//                     current_element++;
//                 }
                
//                 longestStreak = max(longestStreak,count);
//             }
//         }
        
//         return longestStreak;