class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, ans = 0;
        unordered_map<int,int> m;
        while(i < nums.size())
        {
            m[nums[i]]++; 
            while(m[nums[i]] > k) 
            {
                if(--m[nums[j]] == 0) 
                 m.erase(nums[j]); 
               j++;
            }
            ans = max(ans,i-j+1); 
            i++; 
        }
        return ans;
    }
};